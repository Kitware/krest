/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#ifndef krest_core_FileVideoSourceFactory_hpp
#define krest_core_FileVideoSourceFactory_hpp

#include <krest/core/VideoSourceFactory.hpp>

#include <krest/core/Export.h>

#include <qtGlobal.h>

#include <QObject>
#include <QString>

namespace krest
{

namespace core
{

class VideoSource;

class FileVideoSourceFactoryPrivate;

class SEALTK_CORE_EXPORT FileVideoSourceFactory : public VideoSourceFactory
{
  Q_OBJECT

public:
  explicit FileVideoSourceFactory(QObject* parent = nullptr);
  ~FileVideoSourceFactory() override;

  virtual bool expectsDirectory() const;

signals:
  void fileRequested(void* handle);

public slots:
  void requestVideoSource(void* handle) override;

protected:
  QTE_DECLARE_PRIVATE(FileVideoSourceFactory)

private:
  QTE_DECLARE_PRIVATE_RPTR(FileVideoSourceFactory)
};

} // namespace core

} // namespace krest

#endif
