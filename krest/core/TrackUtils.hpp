/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#ifndef krest_core_TrackUtils_hpp
#define krest_core_TrackUtils_hpp

#include <krest/core/Export.h>

#include <vital/types/detected_object.h>
#include <vital/types/detected_object_type.h>
#include <vital/types/object_track_set.h>

#include <QStringList>
#include <QVariantHash>

class QRectF;

namespace krest
{

namespace core
{

kwiver::vital::detected_object_type_sptr
KREST_CORE_EXPORT classificationToDetectedObjectType(
  QVariantHash const& classification);

kwiver::vital::detected_object_sptr
KREST_CORE_EXPORT createDetection(
  QRectF const& detection,
  QVariantHash const& classification = {},
  QStringList const& notes = {});

// ----------------------------------------------------------------------------
inline std::shared_ptr<kwiver::vital::object_track_state> objectTrackState(
  kwiver::vital::track_state_sptr const& state)
{
  return std::static_pointer_cast<kwiver::vital::object_track_state>(state);
}

// ----------------------------------------------------------------------------
inline kwiver::vital::track_state_sptr
createTrackState(
  kwiver::vital::frame_id_t frame, kwiver::vital::time_usec_t time,
  kwiver::vital::detected_object_sptr&& detection)
{
  using state_t = kwiver::vital::object_track_state;
  return std::make_shared<state_t>(frame, time, std::move(detection));
}

} // namespace core

} // namespace krest

#endif
