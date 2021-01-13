/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#include <sealtk/core/FileVideoSourceFactory.hpp>

namespace sealtk
{

namespace core
{

// ============================================================================
class FileVideoSourceFactoryPrivate
{
public:
};

// ----------------------------------------------------------------------------
FileVideoSourceFactory::FileVideoSourceFactory(QObject* parent)
  : VideoSourceFactory{parent},
    d_ptr{new FileVideoSourceFactoryPrivate}
{
}

// ----------------------------------------------------------------------------
FileVideoSourceFactory::~FileVideoSourceFactory()
{
}

// ----------------------------------------------------------------------------
bool FileVideoSourceFactory::expectsDirectory() const
{
  return false;
}

// ----------------------------------------------------------------------------
void FileVideoSourceFactory::requestVideoSource(void* handle)
{
  emit this->fileRequested(handle);
}

} // namespace core

} // namespace sealtk
