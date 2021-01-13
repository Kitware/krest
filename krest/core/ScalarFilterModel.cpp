/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#include <krest/core/ScalarFilterModel.hpp>

#include <krest/core/DataModelTypes.hpp>

#include <vital/range/indirect.h>

#include <QHash>

namespace kvr = kwiver::vital::range;

namespace krest
{

namespace core
{

// ============================================================================
class ScalarFilterModelPrivate
{
public:
  QHash<int, QPair<QVariant, QVariant>> bounds;
};

// ----------------------------------------------------------------------------
QTE_IMPLEMENT_D_FUNC(ScalarFilterModel)

// ----------------------------------------------------------------------------
ScalarFilterModel::ScalarFilterModel(QObject* parent)
  : AbstractProxyModel{parent}, d_ptr{new ScalarFilterModelPrivate}
{
  // Our filtering is dependent on the logical data model's data; therefore, we
  // need to re-filter and/or re-sort when the underlying data changes, and so
  // we enable doing so by default
  this->setDynamicSortFilter(true);
}

// ----------------------------------------------------------------------------
ScalarFilterModel::~ScalarFilterModel()
{
}

// ----------------------------------------------------------------------------
void ScalarFilterModel::setLowerBound(int role, QVariant const& bound)
{
  if (this->isValidData(bound, role))
  {
    QTE_D();

    auto& old = d->bounds[role];
    if (bound != old.first)
    {
      old.first = bound;
      this->invalidateVisibility();
    }
  }
}

// ----------------------------------------------------------------------------
void ScalarFilterModel::setUpperBound(int role, QVariant const& bound)
{
  if (this->isValidData(bound, role))
  {
    QTE_D();

    auto& old = d->bounds[role];
    if (bound != old.second)
    {
      old.second = bound;
      this->invalidateVisibility();
    }
  }
}

// ----------------------------------------------------------------------------
void ScalarFilterModel::setBound(
  int role, QVariant const& lower, QVariant const& upper)
{
  if (this->isValidData(lower, role) && this->isValidData(upper, role))
  {
    QTE_D();

    auto& old = d->bounds[role];
    if (lower != old.first || upper != old.second)
    {
      old.first = lower;
      old.second = upper;
      this->invalidateVisibility();
    }
  }
}

// ----------------------------------------------------------------------------
void ScalarFilterModel::clearLowerBound(int role)
{
  QTE_D();

  auto const& i = d->bounds.find(role);
  if (i != d->bounds.end() && i->first.isValid())
  {
    if (i->second.isValid())
    {
      i->first.clear();
    }
    else
    {
      d->bounds.erase(i);
    }

    this->invalidateVisibility();
  }
}

// ----------------------------------------------------------------------------
void ScalarFilterModel::clearUpperBound(int role)
{
  QTE_D();

  auto const& i = d->bounds.find(role);
  if (i != d->bounds.end() && i->second.isValid())
  {
    if (i->first.isValid())
    {
      i->second.clear();
    }
    else
    {
      d->bounds.erase(i);
    }

    this->invalidateVisibility();
  }
}

// ----------------------------------------------------------------------------
void ScalarFilterModel::clearBound(int role)
{
  QTE_D();

  if (d->bounds.remove(role))
  {
    this->invalidateVisibility();
  }
}

// ----------------------------------------------------------------------------
void ScalarFilterModel::clearBounds()
{
  QTE_D();

  if (!d->bounds.isEmpty())
  {
    d->bounds.clear();
    this->invalidateVisibility();
  }
}

// ----------------------------------------------------------------------------
QVariant ScalarFilterModel::data(QModelIndex const& index, int role) const
{
  if (role == VisibilityRole)
  {
    QTE_D();

    auto* const sm = this->sourceModel();
    auto const& si = this->mapToSource(index);

    for (auto const& i : d->bounds | kvr::indirect)
    {
      auto const role = i.key();
      auto const& sd = sm->data(si, role);
      if (i->first.isValid() && this->lessThan(sd, i->first, role))
      {
        return false;
      }
      if (i->second.isValid() && this->lessThan(i->second, sd, role))
      {
        return false;
      }
    }
  }

  return this->AbstractProxyModel::data(index, role);
}

} // namespace core

} // namespace krest
