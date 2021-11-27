find_package(Catch2 REQUIRED)

add_executable(test_catalogue test_catalogue.cpp)

target_include_directories(test_catalogue PUBLIC ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(test_catalogue PUBLIC Catch2::Catch2 catalogue)

add_test(NAME test_catalogue COMMAND test_catalogue)