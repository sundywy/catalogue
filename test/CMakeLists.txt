find_package(Catch2 REQUIRED)

add_executable(tests test.cpp)
target_link_libraries(tests Catch2::Catch2)

target_include_directories(tests PUBLIC ${CMAKE_SOURCE_DIR}/src)

add_test(NAME tests COMMAND tests)