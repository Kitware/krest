/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#ifndef krest_core_IdentityTransform_hpp
#define krest_core_IdentityTransform_hpp

#include <krest/core/Export.h>

#include <vital/types/transform_2d.h>

namespace krest
{

namespace core
{

class KREST_CORE_EXPORT IdentityTransform : public kwiver::vital::transform_2d
{
public:
  kwiver::vital::transform_2d_sptr clone() const override;

  kwiver::vital::vector_2d map(
    kwiver::vital::vector_2d const& p) const override
  { return p; }

protected:
  kwiver::vital::transform_2d_sptr inverse_() const override;
};

} // namespace core

} // namespace krest

#endif
