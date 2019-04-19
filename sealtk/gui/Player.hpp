/* This file is part of SEAL-TK, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/seal-tk/blob/master/LICENSE for details. */

#ifndef sealtk_gui_Player_hpp
#define sealtk_gui_Player_hpp

#include <sealtk/gui/Export.h>

#include <sealtk/core/VideoSource.hpp>

#include <QMatrix3x3>
#include <QOpenGLWidget>
#include <QPointF>
#include <qtGlobal.h>

#include <vital/types/detected_object_set.h>
#include <vital/types/image_container.h>

class QImage;

namespace sealtk
{

namespace gui
{

Q_NAMESPACE

enum class ContrastMode
{
  Manual,
  Percentile,
};

Q_ENUM_NS(ContrastMode)

class PlayerPrivate;

class SEALTK_GUI_EXPORT Player : public QOpenGLWidget
{
  Q_OBJECT

public:
  explicit Player(QWidget* parent = nullptr);
  ~Player() override;

  Q_PROPERTY(float zoom READ zoom WRITE setZoom NOTIFY zoomChanged);
  Q_PROPERTY(QPointF center READ center WRITE setCenter NOTIFY centerChanged);
  Q_PROPERTY(ContrastMode contrastMode READ contrastMode WRITE setContrastMode)

  float zoom() const;
  QPointF center() const;
  core::VideoSource* videoSource() const;
  ContrastMode contrastMode() const;

signals:
  void zoomChanged(float zoom) const;
  void centerChanged(QPointF center) const;
  void videoSourceChanged(core::VideoSource* videoSource) const;

public slots:
  void setImage(kwiver::vital::image_container_sptr const& image,
                sealtk::core::VideoMetaData const& metaData);
  void setDetectedObjectSet(
    kwiver::vital::detected_object_set_sptr const& detectedObjectSet);
  void setHomography(QMatrix3x3 const& homography);
  void setZoom(float zoom);
  void setCenter(QPointF center);
  void setVideoSource(core::VideoSource* videoSource);
  void setContrastMode(ContrastMode mode);
  void setManualLevels(float low, float high);
  void setPercentiles(double deviance, double tolerance);

protected:
  QTE_DECLARE_PRIVATE(Player)

  void initializeGL() override;
  void paintGL() override;
  void resizeGL(int w, int h) override;

  void paintEvent(QPaintEvent* event) override;

  void mousePressEvent(QMouseEvent* event) override;
  void mouseMoveEvent(QMouseEvent* event) override;
  void mouseReleaseEvent(QMouseEvent* event) override;
  void wheelEvent(QWheelEvent* event) override;

private:
  QTE_DECLARE_PRIVATE_RPTR(Player)
};

}

}

#endif
