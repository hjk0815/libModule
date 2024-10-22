cmake_minimum_required(VERSION 3.10)
project(MyProject VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置安装目录
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/install)

message(STATUS "Current CMakeLists.txt directory: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# 添加库
add_library(my_library STATIC
    src/my_library.cpp
)

target_include_directories(my_library PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# 添加测试子目录
add_subdirectory(test)

# 安装规则
install(TARGETS my_library
    ARCHIVE DESTINATION lib
)
install(FILES include/my_library.h DESTINATION include)

# 安装测试可执行文件
install(TARGETS test_my_library
    RUNTIME DESTINATION bin
)

# 添加自定义目标，在构建后自动执行安装
add_custom_target(auto_install
    COMMAND ${CMAKE_COMMAND} --install ${CMAKE_BINARY_DIR}
    DEPENDS my_library test_my_library
)

# 添加自定义目标，用于安装
add_custom_target(install_all
    COMMAND ${CMAKE_COMMAND} --install ${CMAKE_BINARY_DIR}
    DEPENDS my_library test_my_library
)
