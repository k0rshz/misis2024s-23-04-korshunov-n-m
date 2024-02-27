add_executable(test_complex test_complex.cpp)

target_link_libraries(test_complex complex)

add_executable(test_rational test_rational.cpp)

target_link_libraries(test_rational rational)

add_executable(test_dynarr test_dynarr.cpp)

target_link_libraries(test_dynarr dynarr)

add_executable(test_stackarr test_stackarr.cpp)

target_link_libraries(test_stackarr stackarr)

add_executable(test_stacklst test_stacklst.cpp)

target_link_libraries(test_stacklst stacklst)

add_executable(test_queuelst test_queuelst.cpp)

target_link_libraries(test_queuelst queuelst)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_stacklst)