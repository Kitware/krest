/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#ifndef krest_core_KwiverVideoSource_hpp
#define krest_core_KwiverVideoSource_hpp

#include <krest/core/VideoSource.hpp>

#include <krest/core/Export.h>

#include <qtGlobal.h>

#include <vital/algo/detected_object_set_input.h>
#include <vital/algo/video_input.h>

#include <vital/types/timestamp.h>

#include <QImage>
#include <QObject>
#include <QSet>

namespace krest
{

namespace core
{

class KwiverVideoSourcePrivate;

class SEALTK_CORE_EXPORT KwiverVideoSource : public VideoSource
{
  Q_OBJECT

public:
  explicit KwiverVideoSource(
    kwiver::vital::algo::video_input_sptr const& videoInput,
    QObject* parent = nullptr);
  ~KwiverVideoSource() override;

  bool isReady() const override;
  TimeMap<kwiver::vital::timestamp::frame_t> frames() const override;
  TimeMap<VideoMetaData> metaData() const override;

protected:
  QTE_DECLARE_PRIVATE(KwiverVideoSource)

private:
  explicit KwiverVideoSource(KwiverVideoSourcePrivate* d, QObject* parent);

  QTE_DECLARE_PRIVATE_RPTR(KwiverVideoSource)
};

} // namespace core

} // namespace krest

#endif
