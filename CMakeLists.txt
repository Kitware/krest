# This file is part of Krest, and is distributed under the OSI-approved BSD
# 3-Clause License. See top-level LICENSE file or
# https://github.com/Kitware/krest/blob/master/LICENSE for details.

cmake_minimum_required(VERSION 3.11)
project(krest
  VERSION 0.1
  LANGUAGES CXX
  )

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

set(krest_BUILD_LIBDIR "${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")

list(APPEND CMAKE_MODULE_PATH
  "${PROJECT_SOURCE_DIR}/cmake"
  "${PROJECT_SOURCE_DIR}/cmake/thirdparty"
  )

find_package(kwiver REQUIRED)
find_package(fletch QUIET)
find_package(qtExtensions REQUIRED)
find_package(Qt5 5.10 REQUIRED COMPONENTS
  Test
  Widgets
  Xml
  Concurrent
  Widgets
  Gui
  Core
  )
find_package(Threads REQUIRED)
find_package(Git)
find_package(Sphinx)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_AUTOMOC 1)
set(CMAKE_AUTORCC 1)
set(CMAKE_AUTOUIC 1)

enable_testing()

if(NOT CMAKE_VERSION VERSION_LESS 3.12)
  find_package(Python3)
  if(TARGET Python3::Interpreter)
    if(TARGET Git::Git)
      set(git_args --git $<TARGET_FILE:Git::Git>)
    endif()
    add_test(
      NAME SourceCheck
      COMMAND Python3::Interpreter
      "${PROJECT_SOURCE_DIR}/utilities/source_check.py" ${git_args}
      )
  endif()
endif()

add_subdirectory(krest)

export(EXPORT krest
  NAMESPACE krest::
  FILE "${krest_BUILD_LIBDIR}/cmake/krest/krest-targets.cmake"
  )

install(EXPORT krest
  NAMESPACE krest::
  DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/krest"
  FILE "krest-targets.cmake"
  COMPONENT Development
  )

write_basic_package_version_file(
  "${krest_BUILD_LIBDIR}/cmake/krest/krest-config-version.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
  )

configure_package_config_file(
  "${PROJECT_SOURCE_DIR}/cmake/krest-config.cmake.in"
  "${krest_BUILD_LIBDIR}/cmake/krest/krest-config.cmake"
  INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/krest"
  )

install(FILES
  "${krest_BUILD_LIBDIR}/cmake/krest/krest-config.cmake"
  "${krest_BUILD_LIBDIR}/cmake/krest/krest-config-version.cmake"
  DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/krest"
  COMPONENT Development
  )

configure_file(
  "${PROJECT_SOURCE_DIR}/cmake/setup_KWIVER.sh.in"
  "${PROJECT_BINARY_DIR}/setup_KWIVER.sh"
  @ONLY
  )

configure_file(
  "${PROJECT_SOURCE_DIR}/cmake/setup_KWIVER.bat.in"
  "${PROJECT_BINARY_DIR}/setup_KWIVER.bat"
  @ONLY
  )

if(SPHINX_EXECUTABLE)
  add_subdirectory(doc)
endif()
