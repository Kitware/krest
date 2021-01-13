/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#ifndef krest_core_KwiverFileVideoSourceFactory_hpp
#define krest_core_KwiverFileVideoSourceFactory_hpp

#include <krest/core/FileVideoSourceFactory.hpp>

#include <krest/core/Export.h>

#include <vital/config/config_block.h>

#include <qtGlobal.h>

#include <QObject>
#include <QString>

namespace krest
{

namespace core
{

class VideoSource;

class KwiverFileVideoSourceFactoryPrivate;

class KREST_CORE_EXPORT KwiverFileVideoSourceFactory
  : public FileVideoSourceFactory
{
  Q_OBJECT

public:
  explicit KwiverFileVideoSourceFactory(QObject* parent = nullptr);
  ~KwiverFileVideoSourceFactory() override;

public slots:
  void loadVideoSource(void* handle, QUrl const& uri) override;

protected:
  QTE_DECLARE_PRIVATE(KwiverFileVideoSourceFactory)

  virtual kwiver::vital::config_block_sptr config(
    QUrl const& uri) const = 0;

  virtual QUrl applyFilters(QUrl const& uri, QStringList const& filters);

private:
  QTE_DECLARE_PRIVATE_RPTR(KwiverFileVideoSourceFactory)
};

} // namespace core

} // namespace krest

#endif
