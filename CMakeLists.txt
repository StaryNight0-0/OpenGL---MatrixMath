cmake_minimum_required(VERSION 3.13)

# see https://vcpkg.io/en/docs/users/buildsystems/cmake-integration.html#visual-studio if using visual studio
# On Linux-based distrubtions, use your package manager for dependeices

# VCPKG integration for Windows. See my guide on getting that setup
if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
      CACHE STRING "")
endif()

# Use C++ 20
set(CMAKE_CXX_STANDARD 20)

# Project details start here
project(MyProjectName
	VERSION 0.1
	DESCRIPTION "A brief description of your project here"
	LANGUAGES CXX
)

# Find SDL3 Packages
find_package(SDL3 CONFIG REQUIRED)
find_package(SDL3_image CONFIG REQUIRED)
# SDL3_image vcpkg doesn't set library link target variable :(
set(SDL3_image_LIBRARIES $<IF:$<TARGET_EXISTS:SDL3_image::SDL3_image-shared>, 
  SDL3_image::SDL3_image-shared,
  SDL3_image::SDL3_image-static>
)

# integration for command-line users
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

add_executable( project )
add_subdirectory( src )
target_include_directories(project PUBLIC 
  ${SDL3_INCLUDE_DIRS}
  ${SDL3_IMAGE_INCLUDE_DIRS}
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:include/>
)

target_link_libraries(project PRIVATE 
  ${SDL3_LIBRARIES}
  ${SDL3_image_LIBRARIES}
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/serialib)

# Copy Asset files to binary destination
# make changes to assets trigger the copy in incremental builds
set(PROJ_ASSETS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/data)
file(GLOB_RECURSE PROJ_ASSET_FILES CONFIGURE_DEPENDS
        "${PROJ_ASSETS_DIR}/*"
)

set(ASSET_DST "${CMAKE_CURRENT_BINARY_DIR}")
set(ASSET_STAMP "${CMAKE_CURRENT_BINARY_DIR}/project_assets.stamp")

add_custom_command(
        OUTPUT  ${ASSET_STAMP}
        COMMAND ${CMAKE_COMMAND} -E make_directory ${ASSET_DST}
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJ_ASSETS_DIR}" ${ASSET_DST}
        COMMAND ${CMAKE_COMMAND} -E touch ${ASSET_STAMP}
        DEPENDS ${PROJ_ASSET_FILES}
        COMMENT "Syncing project assets to ${ASSET_DST}"
)
add_custom_target(sync_assets ALL
        DEPENDS ${ASSET_STAMP}
        COMMENT "Ensuring assets are with the Binary"
)
add_dependencies(project sync_assets)
