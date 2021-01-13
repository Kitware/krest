/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#include <sealtk/core/AbstractDataSource.hpp>

namespace sealtk
{

namespace core
{

// ----------------------------------------------------------------------------
AbstractDataSource::AbstractDataSource(QObject* parent) : QObject{parent}
{
}

// ----------------------------------------------------------------------------
AbstractDataSource::~AbstractDataSource()
{
}

} // namespace core

} // namespace sealtk
