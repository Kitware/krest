/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#ifndef krest_core_test_TestVideo_hpp
#define krest_core_test_TestVideo_hpp

#include <krest/core/VideoFrame.hpp>
#include <krest/core/VideoRequest.hpp>
#include <krest/core/VideoRequestor.hpp>
#include <krest/core/VideoSource.hpp>

#include <vital/types/timestamp.h>

#include <QEventLoop>
#include <QVector>

#include <memory>

namespace krest
{

namespace core
{

namespace test
{

// ============================================================================
class TestVideoRequestor
  : public VideoRequestor,
    public std::enable_shared_from_this<TestVideoRequestor>
{
  Q_OBJECT

public:
  void request(VideoSource* source, kwiver::vital::timestamp::time_t time);

  QVector<VideoFrame> receivedFrames;

protected:
  QEventLoop eventLoop;

  void update(VideoRequestInfo const& requestInfo,
              VideoFrame&& response) override;
};

} // namespace test

} // namespace core

} // namespace krest

#endif
