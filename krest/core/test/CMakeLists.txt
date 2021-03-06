# This file is part of Krest, and is distributed under the OSI-approved BSD
# 3-Clause License. See top-level LICENSE file or
# https://github.com/Kitware/krest/blob/master/LICENSE for details.

include(KrestUtils)

krest_add_library(krest::core_test_common
  TYPE STATIC
  NOINSTALL

  SOURCES
    TestCommon.cpp
    TestTrackModel.cpp
    TestTracks.cpp
    TestVideo.cpp
    TestVideoSource.cpp

  PRIVATE_LINK_LIBRARIES
    qtExtensionsHeaders
    Qt5::Core
    Qt5::Test
    krest::core
    kwiver::vital
    kwiver::vital_algo
  )

krest_add_test(KwiverDetectionsSink
  SOURCES
    KwiverDetectionsSink.cpp

  PRIVATE_LINK_LIBRARIES
    krest::core
    krest::core_test_common
  )

krest_add_test(KwiverTracksSink
  SOURCES
    KwiverTracksSink.cpp

  PRIVATE_LINK_LIBRARIES
    krest::core
    krest::core_test_common
  )

krest_add_test(KwiverPipelineWorker
  SOURCES
    KwiverPipelineWorker.cpp

  PRIVATE_LINK_LIBRARIES
    krest::core
    krest::core_test_common
  )

krest_add_test(KwiverTrackModel
  SOURCES
    KwiverTrackModel.cpp

  PRIVATE_LINK_LIBRARIES
    krest::core
    krest::core_test_common
  )

krest_add_test(KwiverTrackSource
  SOURCES
    KwiverTrackSource.cpp

  PRIVATE_LINK_LIBRARIES
    krest::core
    krest::core_test_common
  )

krest_add_test(KwiverVideoSource
  SOURCES
    KwiverVideoSource.cpp

  PRIVATE_LINK_LIBRARIES
    krest::core
    krest::core_test_common
  )

krest_add_test(VideoController
  SOURCES
    VideoController.cpp

  PRIVATE_LINK_LIBRARIES
    krest::core
    krest::core_test_common
  )

krest_add_test(ImageUtils
  SOURCES
    ImageUtils.cpp

  PRIVATE_LINK_LIBRARIES
    krest::core
  )

krest_add_test(AutoLevelsTask
  SOURCES
    AutoLevelsTask.cpp

  PRIVATE_LINK_LIBRARIES
    krest::core
  )

krest_add_test(DateUtils
  SOURCES
    DateUtils.cpp

  PRIVATE_LINK_LIBRARIES
    krest::core
  )

krest_add_test(DirectoryListing
  SOURCES
    DirectoryListing.cpp

  PRIVATE_LINK_LIBRARIES
    krest::core
  )

krest_add_test(ScalarFilterModel
  SOURCES
    ScalarFilterModel.cpp

  PRIVATE_LINK_LIBRARIES
    krest::core
  )

krest_add_test(TimeMap
  SOURCES
    TimeMap.cpp

  PRIVATE_LINK_LIBRARIES
    krest::core
  )

krest_add_test(TimeStamp
  SOURCES
    TimeStamp.cpp

  PRIVATE_LINK_LIBRARIES
    krest::core
  )
