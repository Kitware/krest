/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#ifndef sealtk_core_VideoController_hpp
#define sealtk_core_VideoController_hpp

#include <sealtk/core/TimeMap.hpp>

#include <sealtk/core/Export.h>

#include <qtGlobal.h>

#include <QObject>

#include <memory>

namespace sealtk
{

namespace core
{

class VideoDistributor;
class VideoSource;

class VideoControllerPrivate;

class SEALTK_CORE_EXPORT VideoController : public QObject
{
  Q_OBJECT

  using time_t = kwiver::vital::timestamp::time_t;

public:
  explicit VideoController(QObject* parent = nullptr);
  ~VideoController() override;

  QSet<VideoSource*> videoSources() const;
  VideoDistributor* addVideoSource(VideoSource* videoSource);
  void removeVideoSource(VideoSource* videoSource);

  VideoDistributor* distributor(VideoSource* videoSource) const;

  TimeMap<std::nullptr_t> times();

  time_t time() const;

signals:
  void videoSourcesChanged();
  void timesChanged();
  void timeSelected(time_t time, qint64 requestId);

public slots:
  void seek(time_t time, qint64 requestId = -1);
  void seekNearest(time_t time, qint64 requestId = -1);
  void previousFrame(qint64 requestId = -1);
  void nextFrame(qint64 requestId = -1);

protected:
  QTE_DECLARE_PRIVATE(VideoController)

private:
  QTE_DECLARE_PRIVATE_RPTR(VideoController)
};

} // namespace core

} // namespace sealtk

#endif
