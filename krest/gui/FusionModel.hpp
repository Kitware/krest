/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#ifndef krest_gui_FusionModel_hpp
#define krest_gui_FusionModel_hpp

#include <krest/gui/Export.h>

#include <krest/core/AbstractItemModel.hpp>

#include <qtGlobal.h>

namespace krest
{

namespace gui
{

class FusionModelPrivate;

class KREST_GUI_EXPORT FusionModel : public krest::core::AbstractItemModel
{
  Q_OBJECT

public:
  FusionModel(QObject* parent = nullptr);
  ~FusionModel();

  // Reimplemented from QAbstractItemModel
  int rowCount(QModelIndex const& parent = {}) const override;
  QVariant data(QModelIndex const& index, int role) const override;
  bool setData(
    QModelIndex const& index, QVariant const& value, int role) override;

public slots:
  void addModel(QAbstractItemModel*);
  void removeModel(QAbstractItemModel*);

protected:
  QTE_DECLARE_PRIVATE_PTR(FusionModel);

private:
  QTE_DECLARE_PRIVATE(FusionModel);
};

} // namespace gui

} // namespace krest

#endif
