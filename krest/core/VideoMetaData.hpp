/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#ifndef krest_core_VideoMetaData_hpp
#define krest_core_VideoMetaData_hpp

#include <krest/core/Export.h>

#include <vital/types/timestamp.h>
#include <vital/vital_types.h>

#include <qtGlobal.h>

#include <QSharedDataPointer>

namespace krest
{

namespace core
{

class VideoMetaDataData;

class KREST_CORE_EXPORT VideoMetaData
{
public:
  explicit VideoMetaData(kwiver::vital::timestamp const& timeStamp = {},
                         kwiver::vital::path_t const& imageName = {});
  ~VideoMetaData();

  VideoMetaData(VideoMetaData const&);
  VideoMetaData(VideoMetaData&&);
  VideoMetaData& operator=(VideoMetaData const&);
  VideoMetaData& operator=(VideoMetaData&&);

  kwiver::vital::timestamp timeStamp() const;
  kwiver::vital::path_t imageName() const;

  void setTimeStamp(kwiver::vital::timestamp const&);
  void setImageName(kwiver::vital::path_t const&);

private:
  QTE_DECLARE_SHARED_PTR(VideoMetaData)
  QTE_DECLARE_SHARED(VideoMetaData)
};

} // namespace core

} // namespace krest

#endif
