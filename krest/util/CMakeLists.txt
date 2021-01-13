# This file is part of Krest, and is distributed under the OSI-approved BSD
# 3-Clause License. See top-level LICENSE file or
# https://github.com/Kitware/krest/blob/master/LICENSE for details.

include(KrestUtils)

krest_add_library(krest::util
  TYPE INTERFACE
  HEADERS
    unique.hpp

  TARGET_NAME_VAR name
  )
