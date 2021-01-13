/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#ifndef krest_core_AbstractProxyModel_hpp
#define krest_core_AbstractProxyModel_hpp

#include <krest/core/Export.h>

#include <qtGlobal.h>

#include <QSortFilterProxyModel>

namespace krest
{

namespace core
{

/// Base class for proxy models.
///
/// This class provides a base class for implementing sort/filter proxy models.
/// In particular, it provides a shared mechanism for comparing data that is
/// data-role aware.
class KREST_CORE_EXPORT AbstractProxyModel : public QSortFilterProxyModel
{
  Q_OBJECT

public:
  using QSortFilterProxyModel::QSortFilterProxyModel;

protected:
  /// Test if data is valid.
  ///
  /// This method tests if a data value is valid (i.e. is convertible to the
  /// appropriate type) for a given data role.
  static bool isValidData(QVariant const& data, int role);

  /// Compare data.
  ///
  /// This method performs a comparison of two data items which have the type
  /// \p role. If \p role is not a supported data role, the result is \c false.
  ///
  /// \return \c true if the left data is less than the right data; otherwise
  ///         \c false.
  virtual bool lessThan(
    QVariant const& left, QVariant const& right, int role) const;

  using QSortFilterProxyModel::lessThan;

  /// Emit dataChanged for all top-level items.
  ///
  /// This method emits QAbstractItemModel::dataChanged for all top-level
  /// items, with #VisibilityRole as the list of changed roles. This is useful
  /// for model data filters when their filtering criteria changes.
  void invalidateVisibility();
};

} // namespace core

} // namespace krest

#endif
