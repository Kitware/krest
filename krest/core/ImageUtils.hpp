/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#ifndef krest_core_ImageUtils_hpp
#define krest_core_ImageUtils_hpp

#include <krest/core/Export.h>

#include <vital/types/image_container.h>

class QImage;
class QOpenGLTexture;

namespace krest
{

namespace core
{

QImage KREST_CORE_EXPORT imageContainerToQImage(
  kwiver::vital::image_container_sptr const& image);

void KREST_CORE_EXPORT imageToTexture(
  QOpenGLTexture& texture,
  kwiver::vital::image_container_sptr const& image);

} // namespace core

} // namespace krest

#endif
