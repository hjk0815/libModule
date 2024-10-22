add_executable(test_my_library test_my_library.cpp)
target_link_libraries(test_my_library PRIVATE my_library)

# 设置测试可执行文件的输出目录
set_target_properties(test_my_library PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
