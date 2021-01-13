/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#include <krest/gui/Resources.hpp>

#include <QDir>

static void init()
{
  Q_INIT_RESOURCE(Resources);
}

static void cleanup()
{
  Q_CLEANUP_RESOURCE(Resources);
}

namespace krest
{

namespace gui
{

Resources::Resources()
{
  init();
}

Resources::~Resources()
{
  cleanup();
}

} // namespace gui

} // namespace krest
