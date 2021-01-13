/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#ifndef krest_gui_CreateDetectionPlayerTool_hpp
#define krest_gui_CreateDetectionPlayerTool_hpp

#include <krest/gui/PlayerTool.hpp>

#include <krest/gui/Export.h>

#include <QRectF>

#include <qtGlobal.h>

namespace krest
{

namespace gui
{

class CreateDetectionPlayerToolPrivate;

class KREST_GUI_EXPORT CreateDetectionPlayerTool : public PlayerTool
{
  Q_OBJECT

public:
  CreateDetectionPlayerTool(Player* parent = nullptr);
  ~CreateDetectionPlayerTool();

signals:
  void detectionCreated(QRectF const& detection) const;

protected:
  QTE_DECLARE_PRIVATE_RPTR(CreateDetectionPlayerTool)

  void activate() override;
  void deactivate() override;
  void updateImage() override;
  void mousePressEvent(QMouseEvent* event) override;
  void mouseReleaseEvent(QMouseEvent* event) override;
  void mouseMoveEvent(QMouseEvent* event) override;
  void paintGL() override;

private:
  QTE_DECLARE_PRIVATE(CreateDetectionPlayerTool)
};

} // namespace gui

} // namespace krest

#endif
