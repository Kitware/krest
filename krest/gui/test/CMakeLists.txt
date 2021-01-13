# This file is part of Krest, and is distributed under the OSI-approved BSD
# 3-Clause License. See top-level LICENSE file or
# https://github.com/Kitware/krest/blob/master/LICENSE for details.

include(KrestUtils)

krest_add_test(AbstractItemRepresentation
  SOURCES
    AbstractItemRepresentation.cpp

  PRIVATE_LINK_LIBRARIES
    krest::gui
    krest::core
  )

krest_add_test(FusionModel
  SOURCES
    FusionModel.cpp

  PRIVATE_LINK_LIBRARIES
    krest::gui
    krest::core
  )
