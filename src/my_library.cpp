#include "my_library.h"
#include <iostream>
/* // dll 导出宏
// 在实现文件中重新定义 MY_LIBRARY_API 为空
#undef MY_LIBRARY_API
#define MY_LIBRARY_API
*/

void MyClass::sayHello() {
    std::cout << "Hello from MyClass!" << std::endl;
}

void sayHelloWorld() {
    std::cout << "Hello, World!" << std::endl;
}
