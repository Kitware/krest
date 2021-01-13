/* This file is part of Krest, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/krest/blob/master/LICENSE for details. */

#ifndef krest_test_TestCore_hpp
#define krest_test_TestCore_hpp

#include <QString>

#define SEALTK_TEST_DATA_PATH(f) QStringLiteral(SEALTK_TEST_DATA_DIR "/" f)

namespace krest
{

namespace test
{

static inline QString testDataPath(QString const& path)
{
  return QStringLiteral(SEALTK_TEST_DATA_DIR "/") + path;
}

} // namespace test

} // namespace krest

#endif
