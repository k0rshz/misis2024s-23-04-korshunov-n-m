cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

include(cmake/Vcpkg.cmake)

project(
    "PROJECT"
    VERSION 0.1.0
    LANGUAGES CXX
)

set(PRJ_HEADERS )
set(PRJ_SOURCES )
set(PRJ_MAIN app/matrix_calculator.cpp)

set(PRJ_LIBRARIES 
    fmt::fmt
    SDL2::SDL2
    imgui::imgui
    OpenGL::GL
)

set(CMAKE_PREFIX_PATH "vcpkg/packages/fmt_x64-windows;vcpkg/packages/sdl2_x64-windows;vcpkg/packages/imgui_x64-windows;vcpkg/packages/opengl_x64-windows")

find_package(fmt CONFIG REQUIRED)

find_package(SDL2 CONFIG REQUIRED)

find_package(imgui CONFIG REQUIRED)

find_package(OpenGL REQUIRED)

add_executable(${PROJECT_NAME} ${PRJ_HEADERS} ${PRJ_SOURCES} ${PRJ_MAIN})
target_link_libraries(${PROJECT_NAME} PRIVATE ${PRJ_LIBRARIES})

target_link_libraries(${PROJECT_NAME}  PRIVATE matrix)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PRJ_MAIN})

add_subdirectory(test)
add_subdirectory(matrix)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


find_file(SDL2d_DLL sdl2d.dll PATHS "vcpkg/packages/sdl2_x64-windows/debug/bin" REQUIRED)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_if_different
                   ${SDL2d_DLL} $<TARGET_FILE_DIR:${PROJECT_NAME}>)