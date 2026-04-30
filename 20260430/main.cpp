#include <iostream>
#include <cstring>

typedef unsigned long long int64;

using namespace std;

const int MAX = 3;

int example1()
{
    int *pointer;
    // int *pointer = NULL; // 空指针
    int value = 1000;

    pointer = &value;

    std::cout << "指针变量 pointer 的地址: " << pointer << std::endl;
    std::cout << "指针变量 pointer 的值:   " << *pointer << std::endl;
    std::cout << std::endl;
    std::cout << "变量 value 的地址: " << &value << std::endl;
    std::cout << "变量 value 的值:   " << value << std::endl;

    return 0;
}

int example2()
{
    int var[MAX] = {10, 100, 200};

    cout << "var 指向的内存地址: " << var << endl;
    cout << "var 的第1个元素: " << *(var) << endl;
    cout << "var 的第1个元素: " << var[0] << endl;

    cout << "var 指向的内存地址: " << &var[0] << endl;

    cout << "var 的第2个元素: " << *(var + 1) << endl;
    cout << "var 的第2个元素: " << var[1] << endl;

    cout << "var 指向的内存地址: " << &var[1] << endl;

    cout << "var 的第3个元素: " << *(var + 2) << endl;
    cout << "var 的第3个元素: " << var[2] << endl;

    cout << "var 指向的内存地址: " << &var[2] << endl;
    return 0;
}

int example3()
{
    int var[MAX] = {10, 100, 200};
    int *ptr;

    // 指针中的数组地址
    ptr = var;

    for (int i = 0; i < MAX; i++)
    {
        cout << "var 指向的内存地址: " << var << endl;
        cout << "var[" << i << "]的内存地址为 " << ptr << endl;
        cout << "ptr 当前指向的内存地址: " << ptr << endl;

        cout << "var[" << i << "] 的值为 ";
        cout << *ptr << endl;

        // 移动到下一个位置
        ptr++;
    }
    return 0;
}

int example4()
{
    int var[MAX] = {10, 100, 200};

    for (int i = 0; i < MAX; i++)
    {
        *var = i; // 这是正确的语法
        // var++; // 这是不正确的 (报错)

        cout << "var[" << i << "] 的值为 ";
        cout << *(var + i) << endl;
    }
    return 0;
}

int example5()
{
    int var[MAX] = {10, 100, 200};
    int *ptr[MAX];

    for (int i = 0; i < MAX; i++)
    {
        ptr[i] = &var[i]; // 赋值为整数的地址
    }

    for (int i = 0; i < MAX; i++)
    {
        cout << "Value of var[" << i << "] = ";
        cout << *ptr[i] << endl;
    }
    return 0;
}

int example6()
{
    char a = 'a'; // 变量 a 是字符类型，仅支持 ASCII 编码表中的有效字符

    // \0: 终止符

    const char *ab = "ab";    // 常量字符串/字符指针，不可修改，因为 "AB" 存放在常量区 而不是 栈区 (只读); 已经自动补全终止符
    char _ab[2] = {'a', 'b'}; // 需要自己补全终止符

    // *(ab) = 'V'; // 非法操作, 不允许对常量进行修改

    cout << *(ab) << endl; // 但是可以读取

    cout << *(_ab + 1) << endl;

    _ab[1] = 'c';

    cout << *(_ab + 1) << endl;
    cout << endl << endl << endl;


    const char *abcdef = "abcdef";
    // const char ghijkl[6] = {'g', 'h', 'i', 'j', 'k', 'l'}; // 缺失终止符 '\0', 会报错
    // main.cpp:136:34: warning: 'size_t strlen(const char*)' argument missing terminating nul [-Wstringop-overread]
    //                                                      ↓ 一定要加!
    char ghijkl[7] = {'g', 'h', 'i', 'j', 'k', 'l', '\0'};

    cout << abcdef << endl;

    for(size_t i = 0; i < strlen(abcdef); i++)
    {
        // cout << *(abcdef + i) << endl;
        cout << abcdef[i] << endl;
    }

    for(size_t i = 0; i < strlen(ghijkl); i++)
    {
        if (ghijkl[i] == 'l')
        {
            ghijkl[i] = 'L';
        }

        cout << ghijkl[i] << endl;
    }
    return 0;
}

int main()
{
    const char *names[MAX] = { "Tommy", "Alisa", "Tony" };

    for (int i = 0; i < MAX; i++)
    {
        cout << "Value of names[" << i << "] = ";
        cout << names[i] << endl;
    }
    return 0;
}