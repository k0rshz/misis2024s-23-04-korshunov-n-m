add_library(matrix matrix.cpp matrix.hpp)
set_property(TARGET matrix PROPERTY CXX_STANDARD 20)
target_include_directories(matrix PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)