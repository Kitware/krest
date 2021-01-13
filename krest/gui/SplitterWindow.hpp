/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#ifndef krest_gui_SplitterWindow_hpp
#define krest_gui_SplitterWindow_hpp

#include <krest/gui/Export.h>

#include <qtGlobal.h>

#include <QWidget>

namespace krest
{

namespace gui
{

class SplitterWindowPrivate;

class Window;

class KREST_GUI_EXPORT SplitterWindow : public QWidget
{
  Q_OBJECT

public:
  explicit SplitterWindow(QWidget* parent = nullptr);
  ~SplitterWindow() override;

  QWidget* centralWidget() const;
  void setCentralWidget(QWidget* widget);
  bool closable() const;
  void setClosable(bool closable);
  void setFilenameVisible(bool visible);
  void setFilename(QString const& filename);

signals:
  void visibilityChanged(bool visible);

protected:
  QTE_DECLARE_PRIVATE(SplitterWindow)

  void showEvent(QShowEvent *event) override;
  void hideEvent(QHideEvent *event) override;

private:
  QTE_DECLARE_PRIVATE_RPTR(SplitterWindow)
};

} // namespace gui

} // namespace krest

#endif
