/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#ifndef krest_core_VideoSourceFactory_hpp
#define krest_core_VideoSourceFactory_hpp

#include <krest/core/Export.h>

#include <qtGlobal.h>

#include <QObject>

namespace krest
{

namespace core
{

class VideoSource;

class VideoSourceFactoryPrivate;

class KREST_CORE_EXPORT VideoSourceFactory : public QObject
{
  Q_OBJECT

public:
  explicit VideoSourceFactory(QObject* parent = nullptr);
  ~VideoSourceFactory() override;

signals:
  void videoSourceLoaded(void* handle, VideoSource* videoSource);

public slots:
  virtual void requestVideoSource(void* handle) = 0;
  virtual void loadVideoSource(void* handle, QUrl const& uri) = 0;

protected:
  QTE_DECLARE_PRIVATE(VideoSourceFactory)

private:
  QTE_DECLARE_PRIVATE_RPTR(VideoSourceFactory)
};

} // namespace core

} // namespace krest

#endif
