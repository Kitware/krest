# This file is part of Krest, and is distributed under the OSI-approved BSD
# 3-Clause License. See top-level LICENSE file or
# https://github.com/Kitware/krest/blob/master/LICENSE for details.

execute_process(
  COMMAND "${GIT_EXECUTABLE}" describe --dirty --always
  OUTPUT_VARIABLE KREST_VERSION
  OUTPUT_STRIP_TRAILING_WHITESPACE
  ERROR_QUIET
  WORKING_DIRECTORY "${KREST_SOURCE_DIR}"
  )

if(NOT KREST_VERSION)
  set(KREST_VERSION "${KREST_VERSION_FALLBACK}")
endif()

configure_file(
  "${KREST_VERSION_IN}"
  "${KREST_VERSION_OUT}"
  )
