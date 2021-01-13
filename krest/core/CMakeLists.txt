# This file is part of Krest, and is distributed under the OSI-approved BSD
# 3-Clause License. See top-level LICENSE file or
# https://github.com/Kitware/krest/blob/master/LICENSE for details.

include(KrestUtils)

set(KREST_CORE_VERSION_IN
  "${PROJECT_SOURCE_DIR}/krest/core/Version.h.in")
set(KREST_CORE_VERSION_OUT
  "${PROJECT_BINARY_DIR}/krest/core/Version.h")

krest_add_library(krest::core
  SOURCES
    AbstractDataSink.cpp
    AbstractDataSource.cpp
    AbstractItemModel.cpp
    AbstractProxyModel.cpp
    AutoLevelsTask.cpp
    DataModelTypes.cpp
    DateUtils.cpp
    DirectoryListing.cpp
    FileVideoSourceFactory.cpp
    IdentityTransform.cpp
    ImageUtils.cpp
    KwiverFileVideoSourceFactory.cpp
    KwiverDetectionsSink.cpp
    KwiverTrackModel.cpp
    KwiverTracksSink.cpp
    KwiverPipelinePortSet.cpp
    KwiverPipelineWorker.cpp
    KwiverTrackSource.cpp
    KwiverVideoSource.cpp
    ScalarFilterModel.cpp
    TimeStamp.cpp
    TrackUtils.cpp
    VideoController.cpp
    VideoDistributor.cpp
    VideoMetaData.cpp
    VideoRequest.cpp
    VideoRequestor.cpp
    VideoSource.cpp
    VideoSourceFactory.cpp

  HEADERS
    AbstractDataSink.hpp
    AbstractDataSource.hpp
    AbstractItemModel.hpp
    AbstractProxyModel.hpp
    AutoLevelsTask.hpp
    DataModelTypes.hpp
    DateUtils.hpp
    DirectoryListing.hpp
    FileVideoSourceFactory.hpp
    IdentityTransform.hpp
    ImageUtils.hpp
    KwiverFileVideoSourceFactory.hpp
    KwiverDetectionsSink.hpp
    KwiverTrackModel.hpp
    KwiverTracksSink.hpp
    KwiverPipelinePortSet.hpp
    KwiverPipelineWorker.hpp
    KwiverTrackSource.hpp
    KwiverVideoSource.hpp
    ScalarFilterModel.hpp
    TimeMap.hpp
    TimeStamp.hpp
    TrackUtils.hpp
    UnsharedPointer.hpp
    VideoController.hpp
    VideoDistributor.hpp
    VideoFrame.hpp
    VideoMetaData.hpp
    VideoProvider.hpp
    VideoRequest.hpp
    VideoSource.hpp
    VideoSourceFactory.hpp
    "${KREST_CORE_VERSION_OUT}"

  PUBLIC_LINK_LIBRARIES
    krest::util
    kwiver::kwiver_algo_qt
    kwiver::vital
    qtExtensions
    Qt5::Core
    Threads::Threads

  EXPORT_HEADER Export.h
  TARGET_NAME_VAR name
  )

set(KREST_VERSION "v${PROJECT_VERSION}")
if(TARGET Git::Git)
  add_custom_target(krest_core_version
    COMMAND "${CMAKE_COMMAND}"
      "-DGIT_EXECUTABLE:FILEPATH=$<TARGET_FILE:Git::Git>"
      "-DKREST_SOURCE_DIR:PATH=${PROJECT_SOURCE_DIR}"
      "-DKREST_VERSION_FALLBACK:STRING=${KREST_VERSION}"
      "-DKREST_VERSION_IN:FILEPATH=${KREST_CORE_VERSION_IN}"
      "-DKREST_VERSION_OUT:FILEPATH=${KREST_CORE_VERSION_OUT}"
      -P "${PROJECT_SOURCE_DIR}/cmake/GenerateVersion.cmake"
    BYPRODUCTS "${KREST_CORE_VERSION_OUT}"
    )
  add_dependencies(${name} krest_core_version)
else()
  configure_file(
    "${KREST_CORE_VERSION_IN}"
    "${KREST_CORE_VERSION_OUT}"
    )
endif()

add_subdirectory(test)
