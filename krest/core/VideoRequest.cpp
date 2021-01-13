/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#include <krest/core/VideoRequest.hpp>

#include <krest/core/VideoFrame.hpp>
#include <krest/core/VideoRequestor.hpp>

namespace krest
{

namespace core
{

// ----------------------------------------------------------------------------
void VideoRequest::sendReply(VideoFrame&& frame) const
{
  auto* const requestor = this->requestor.get();
  auto const info = VideoRequestInfo{*this};

  QMetaObject::invokeMethod(
    requestor, [requestor, info, frame = std::move(frame)]() mutable {
      requestor->update(info, std::move(frame));
    });
}

} // namespace core

} // namespace krest
