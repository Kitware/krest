/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#ifndef krest_core_VideoFrame_hpp
#define krest_core_VideoFrame_hpp

#include <krest/core/VideoMetaData.hpp>

#include <vital/types/image_container.h>

namespace krest
{

namespace core
{

// ============================================================================
struct VideoFrame
{
  kwiver::vital::image_container_sptr image;
  VideoMetaData metaData;
};

} // namespace core

} // namespace krest

#endif
