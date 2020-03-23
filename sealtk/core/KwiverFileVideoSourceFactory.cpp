/* This file is part of SEAL-TK, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/seal-tk/blob/master/LICENSE for details. */

#include <sealtk/core/KwiverFileVideoSourceFactory.hpp>

#include <sealtk/core/KwiverVideoSource.hpp>

#include <vital/algo/video_input.h>

#include <qtStlUtil.h>

namespace sealtk
{

namespace core
{

// ============================================================================
class KwiverFileVideoSourceFactoryPrivate
{
public:
};

// ----------------------------------------------------------------------------
QTE_IMPLEMENT_D_FUNC(KwiverFileVideoSourceFactory)

// ----------------------------------------------------------------------------
KwiverFileVideoSourceFactory::KwiverFileVideoSourceFactory(QObject* parent)
  : FileVideoSourceFactory{parent},
    d_ptr{new KwiverFileVideoSourceFactoryPrivate}
{
}

// ----------------------------------------------------------------------------
KwiverFileVideoSourceFactory::~KwiverFileVideoSourceFactory()
{
}

// ----------------------------------------------------------------------------
void KwiverFileVideoSourceFactory::loadVideoSource(
  void* handle, QUrl const& uri)
{
  kwiver::vital::algo::video_input_sptr vi;
  kwiver::vital::algo::video_input::set_nested_algo_configuration(
    "video_reader", this->config(uri), vi);
  if (vi)
  {
    vi->open(stdString(uri.toLocalFile()));

    auto* vs = new KwiverVideoSource{vi, this->parent()};
    emit this->videoSourceLoaded(handle, vs);
  }
}

} // namespace core

} // namespace sealtk
