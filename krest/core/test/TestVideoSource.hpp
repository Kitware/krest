/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#ifndef krest_core_test_TestVideoSource_hpp
#define krest_core_test_TestVideoSource_hpp

#include <krest/core/VideoMetaData.hpp>
#include <krest/core/VideoProvider.hpp>
#include <krest/core/VideoSource.hpp>

namespace krest
{

namespace core
{

namespace test
{

// ============================================================================
class SimpleVideoSource : public core::VideoSource
{
public:
  SimpleVideoSource(TimeMap<VideoMetaData> const& data);

  bool isReady() const override;
  TimeMap<VideoMetaData> metaData() const override;
  TimeMap<kwiver::vital::timestamp::frame_t> frames() const override;

private:
  class Provider : public core::VideoProvider
  {
  public:
    void initialize() override {}

    kwiver::vital::timestamp processRequest(
      core::VideoRequest&&, kwiver::vital::timestamp const&) override
    { return {}; }
  };

  SimpleVideoSource(Provider* provider, TimeMap<VideoMetaData> const& data);

  std::unique_ptr<Provider> provider;
  TimeMap<VideoMetaData> const data;
};

} // namespace test

} // namespace core

} // namespace krest

#endif
