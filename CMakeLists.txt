project(misis2024s-23-04-korshunov-n-m)

cmake_minimum_required(VERSION 3.20)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/bin.dbg)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin.rel)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_CURRENT_SOURCE_DIR}bin.relwithdbg)

option(BUILD_WITH_CODEFORCES "Build prj.codeforces targets" off)
option(BUILD_WITH_SAMPLES    "Build prj.cw sample targets"  off )

add_subdirectory(prj.codeforces)


add_subdirectory(prj.lab)
add_subdirectory(prj.test)

if (BUILD_WITH_CW)
  add_subdirectory(prj.cw)
endif()


# add_subdirectory(prj.cw)
