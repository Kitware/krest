/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#include <krest/core/VideoSourceFactory.hpp>

namespace krest
{

namespace core
{

// ============================================================================
class VideoSourceFactoryPrivate
{
public:
};

// ----------------------------------------------------------------------------
QTE_IMPLEMENT_D_FUNC(VideoSourceFactory)

// ----------------------------------------------------------------------------
VideoSourceFactory::VideoSourceFactory(QObject* parent)
  : QObject{parent}, d_ptr{new VideoSourceFactoryPrivate}
{
}

// ----------------------------------------------------------------------------
VideoSourceFactory::~VideoSourceFactory()
{
}

} // namespace core

} // namespace krest
