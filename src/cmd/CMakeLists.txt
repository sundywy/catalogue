add_executable(demo main.cpp)

target_include_directories(demo PUBLIC ${PROJECT_SOURCE_DIR}/src)

target_link_libraries(demo PUBLIC catalogue)