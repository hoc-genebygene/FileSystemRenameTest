project(FileSystemRenameTest CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED filesystem)
include_directories(${Boost_INCLUDE_DIR})


add_executable(rename_test rename_test.cpp)
target_link_libraries(rename_test ${Boost_LIBRARIES})
