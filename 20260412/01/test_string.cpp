/**
 * Author: HanskiJay (Tommy131)
 * Time: 2026.04.12 23:38
 * Version 1.0
 */
#include <iostream>
#include <string>

using namespace std;

/*
==============================
一、函数声明（Function Declaration）
==============================
*/
void test(int value);        // 传值调用（Call by Value）
void test_ref(int &ref);     // 引用调用（Call by Reference）

/*
==============================
二、函数定义
==============================
*/

// 传值调用：不会改变原变量
void test(int value)
{
    cout << "[test] 接收到的 value = " << value << endl;

    value = 100;  // 修改的是副本，不影响原变量
    cout << "[test] 修改后的 value = " << value << endl;
}

// 引用调用：会直接修改原变量
void test_ref(int &ref)
{
    cout << "[test_ref] 接收到的 ref = " << ref << endl;

    ref = 999;  // 直接修改原变量
    cout << "[test_ref] 修改后的 ref = " << ref << endl;
}

/*
==============================
三、主函数：演示传值 vs 引用
==============================
*/
int main()
{
    int value = 0;
    int ref = 3;

    cout << "初始值: value = " << value << ", ref = " << ref << endl;

    test(value);       // 不改变 value
    test_ref(ref);     // 改变 ref

    cout << "最终值: value = " << value << ", ref = " << ref << endl;

    return 0;
}

/*
==============================
四、string 字符串操作示例
==============================
*/
int main_string()
{
    string welcome = "Hello world!";  // 自动带 '\0'

    cout << welcome << endl;

    // 修改字符串中的字符
    welcome[6] = 'W';
    cout << "修改后: " << welcome << endl;

    // 字符串长度
    cout << "长度: " << welcome.length() << endl;

    // 查找字符串（返回位置，找不到返回 string::npos）
    size_t pos = welcome.find("World");
    cout << "查找 World 位置: " << pos << endl;

    return 0;
}

/*
==============================
五、字符输入示例
==============================
*/
int main_input()
{
    char c;
    string line;

    cout << "请输入一行字符（按回车结束）：" << endl;

    // 逐字符读取
    while (cin.get(c) && (c != '\n'))
    {
        line += c;   // 拼接字符
        cout << "当前输入: " << line << endl;
    }

    cout << "最终输入: " << line << endl;

    return 0;
}

/*
==============================
六、C++ 基本数据类型示例
==============================
*/
int main_types()
{
    // 整型
    int a = 10;
    short b = 20;
    long c = 100000;
    long long d = 10000000000;

    // 浮点型
    float e = 3.14f;
    double f = 3.1415926;

    // 字符型
    char g = 'A';

    // 布尔型
    bool h = true;

    cout << "=== 基本类型 ===" << endl;
    cout << "int: " << a << endl;
    cout << "short: " << b << endl;
    cout << "long: " << c << endl;
    cout << "long long: " << d << endl;
    cout << "float: " << e << endl;
    cout << "double: " << f << endl;
    cout << "char: " << g << endl;
    cout << "bool: " << h << endl;

    return 0;
}

/*
==============================
七、数组示例
==============================
*/
int main_array()
{
    int arr[5] = {1, 2, 3, 4, 5};

    cout << "数组元素：" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    return 0;
}

/*
==============================
八、指针示例
==============================
*/
int main_pointer()
{
    int x = 10;
    int *p = &x;  // 指针存储变量地址

    cout << "x 的值: " << x << endl;
    cout << "x 的地址: " << &x << endl;
    cout << "指针 p 存的地址: " << p << endl;
    cout << "通过指针访问值: " << *p << endl;

    // 修改值
    *p = 20;
    cout << "修改后 x = " << x << endl;

    return 0;
}

/*
==============================
九、引用示例（Reference）
==============================
*/
int main_reference()
{
    int x = 5;
    int &ref = x;  // ref 是 x 的别名

    ref = 100;

    cout << "x = " << x << endl;   // 100
    cout << "ref = " << ref << endl;

    return 0;
}