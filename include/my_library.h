#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H

#ifdef __cplusplus
extern "C" {
#endif

class MyClass {
public:
    void sayHello();
};

void sayHelloWorld();

#ifdef __cplusplus
}
#endif

#endif // MY_LIBRARY_H




/*  dll 导出宏
#ifdef _WIN32
    #ifdef MY_LIBRARY_EXPORTS
        #define MY_LIBRARY_API __declspec(dllexport)
    #else
        #define MY_LIBRARY_API __declspec(dllimport)
    #endif
#else
    #define MY_LIBRARY_API __attribute__((visibility("default")))
#endif

class MY_LIBRARY_API MyClass {
public:
    void sayHello();
};

#ifdef __cplusplus
extern "C" {
#endif

MY_LIBRARY_API void sayHelloWorld();

#ifdef __cplusplus
}
#endif

#endif // MY_LIBRARY_H



*/
