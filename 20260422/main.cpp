#include <iostream>
#include "main.h"

int global_integer = 1;

// 定义 (declaration) integer_and_boolean 函数
void integer_and_boolean()
{
    std::cout << "[integer_and_boolean]" << std::endl;

    // 初始化两个类型为 整型 (integer) 的变量
    int value, result;
    bool boolean = true;

    value = 1;
    result = value + value;
    // 等价
    result = 1 + 1;

    std::cout << "结果: " << result << std::endl;
}

char toLowerLetter(char letter)
{
    // [A ; Z]
    if (letter >= 65 && letter <= 90)
    {
        return letter + 32;
    }
    else
    {
        return letter;
    }

   /*  char upper = 'A';
    char lower = (upper >= 'A' && upper <= 'Z') ? static_cast<char>(upper + ('a' - 'A')) : upper;
    std::cout << upper << " -> " << lower << std::endl; */
}

void char_declaration()
{
    char ch1 = 'n';
    char ch2 = 'i';
    // char *chs = "ni";

    // TODO: (to Jay) 研究一下怎么使用 wchar_t 输出 unicode 字符
    // wchar_t _wchar_t = L'你';
    // std::wcout << _wchar_t << std::endl;

    // 字母大写转换到小写
    char knownLetter = 'A';
    std::cout << toLowerLetter(knownLetter) << std::endl;
}

void float_double_declaration()
{
    // 1. 单精度浮点型 (float) - 32位，约7位有效数字 [11, 13]
    float myFloat = 12.123456789;

    // 2. 双精度浮点型 (double) - 64位，约15-17位有效数字 [11, 13]
    double myDouble = 12.123456789123;

    // 3. 科学计数法
    // double scientific = 1.23e-4;

    printf("Float: %.7f\n", myFloat);    // 输出 3.1415927
    printf("Double: %.15f\n", myDouble); // 输出 3.141592653589793

    // 等价于 int integer = 1;
    integer _integer = 1;
}

void enum_declaration()
{
    enum color
    {
        blue,
        red = 6,
        green
    } c;
    c = green;

    std::cout << c << std::endl;
}

void calculation_declaration()
{
    int a, b, c, result_1, result_2, result_3;

    a = 10;
    b = 150;
    c = 2;

    result_1 = a * c + 150;       // output: 170
    result_2 = a * (c + 150);     // output: 1520
    result_3 = a / (2 * c) + 150; // output: 152

    std::cout << "result_1: " << result_1 << std::endl;
    std::cout << "result_2: " << result_2 << std::endl;
    std::cout << "result_3: " << result_3 << std::endl;

    int special_increase = 1;
    std::cout << "[Step 1] special_increase: " << special_increase << std::endl;   // 单纯输出变量
    std::cout << "[Step 2] special_increase: " << ++special_increase << std::endl; // 首先 自增变量 special_increase 的值, 然后输出自增后的结果
    std::cout << "[Step 3] special_increase: " << special_increase++ << std::endl; // 先   输出变量 special_increase 的值, 然后才对其自增运算
    std::cout << "[Step 4] special_increase: " << special_increase << std::endl;   // 单纯输出变量
    //++ 自增运算符, 整数值增加 1, special_increase++ 将得到 1

    std::cout << "--------------------------------" << std::endl;

    int special_dencent = 1;
    std::cout << "[Step 1] special_dencent: " << special_dencent << std::endl;   // 单纯输出变量
    std::cout << "[Step 2] special_dencent: " << --special_dencent << std::endl; // 首先 自减变量 special_dencent 的值, 然后输出自减后的结果
    std::cout << "[Step 3] special_dencent: " << special_dencent-- << std::endl; // 先   输出变量 special_dencent 的值, 然后才对其自减运算
    std::cout << "[Step 4] special_dencent: " << special_dencent << std::endl;   // 单纯输出变量
    // -- 自减运算符, 整数值减少 1, special_increase-- 将得到 0

    std::cout << "--------------------------------" << std::endl;

    int me = 0;
    std::cout << "[Step 1] value me: " << me << std::endl;
    me += 1; // 等价于 me = me + 1
    std::cout << "[Step 2] value me: " << me << std::endl;
    me *= 8; // 等价于 me = me * 8
    std::cout << "[Step 3] value me: " << me << std::endl;
    me /= 2; // 等价于 me = me / 2
    std::cout << "[Step 4] value me: " << me << std::endl;
    me = +114514; // 等价于 me = +114514
    std::cout << "[Step 5] value me: " << me << std::endl;
    me = -10086; // 等价于 me = -10086
    std::cout << "[Step 6] value me: " << me << std::endl;
}

void operation_declaration()
{
    // 关系运算符
    std::cout << "1 == 1 ? " << ((1 == 1) ? "true" : "false") << std::endl;
    std::cout << "1 == 2 ? " << ((1 == 2) ? "true" : "false") << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "1 != 1 ? " << ((1 != 1) ? "true" : "false") << std::endl;
    std::cout << "1 != 2 ? " << ((1 != 2) ? "true" : "false") << std::endl;
    std::cout << "--------------------------------" << std::endl;

    std::cout << "1 > 1 ? " << ((1 > 1) ? "true" : "false") << std::endl;
    std::cout << "1 > 2 ? " << ((1 > 2) ? "true" : "false") << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "1 < 1 ? " << ((1 < 1) ? "true" : "false") << std::endl;
    std::cout << "1 < 2 ? " << ((1 < 2) ? "true" : "false") << std::endl;
    std::cout << "--------------------------------" << std::endl;

    std::cout << "1 >= 1 ? " << ((1 >= 1) ? "true" : "false") << std::endl;
    std::cout << "1 >= 2 ? " << ((1 >= 2) ? "true" : "false") << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "1 <= 1 ? " << ((1 <= 1) ? "true" : "false") << std::endl;
    std::cout << "1 <= 2 ? " << ((1 <= 2) ? "true" : "false") << std::endl;
    std::cout << "--------------------------------" << std::endl;

    int amount = 100;
    bool isMember = true;

    // 逻辑运算符: && (并且; 和)
    if (amount >= 10 && isMember == true)
    {
        std::cout << "余额充足，并且是会员" << std::endl;
    }
    else
    {
        std::cout << "条件不成立" << std::endl;
    }

    // 逻辑运算符: || (或者)
    if (amount <= 10 || isMember == true)
    {
        std::cout << "可以购买" << std::endl;
    }
    else
    {
        std::cout << "不可以购买" << std::endl;
    }

    // 逻辑运算符: 并列使用
    int quantity = 3;
    if ((amount >= 10 && quantity >= 1) || isMember == true)
    {
        std::cout << "可以购买" << std::endl;
    }
    else
    {
        std::cout << "不可以购买" << std::endl;
    }

    // 等价于: isMember != true
    if (!isMember) // 判断 isMember 是否 **不是** 真 (true)
    {
        std::cout << "不是会员" << std::endl;
    }
    else
    {
        std::cout << "是会员" << std::endl;
    }

    // 上方代码等价于下方的三元表达式简化版本
    std::cout << (!isMember ? "不是" : "是") << "会员" << std::endl;

    // 例子2: 年龄判断
    int age = 20;
    bool is_His_Age_Bigger_Than_or_equal_20 = age >= 20;
    std::cout << (is_His_Age_Bigger_Than_or_equal_20 ? "是" : "不是") << std::endl;
}

// 这个是c++的主函数, 程序的入口
int main()
{
    // 设置区域为本地系统环境（支持中文）
    std::setlocale(LC_ALL, "");

    integer_and_boolean();
    std::cout << "------------------------------------------------------" << std::endl;
    char_declaration();
    std::cout << "------------------------------------------------------" << std::endl;
    float_double_declaration();
    std::cout << "------------------------------------------------------" << std::endl;
    enum_declaration();
    std::cout << "------------------------------------------------------" << std::endl;
    calculation_declaration();
    std::cout << "------------------------------------------------------" << std::endl;
    operation_declaration();
    std::cout << "------------------------------------------------------" << std::endl;

    std::cout << global_integer << std::endl;

    // 假设一个使用场景，明确知道这个值永远都不会发生改变时，可以使用标识符 const 定义这是一个常量
    // const int CONSTANT = 1;

    std::cout << "Hello, world!" << std::endl;
    return 0;
}