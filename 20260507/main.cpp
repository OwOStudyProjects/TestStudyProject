#include <iostream>
#include <windows.h>

#include "person.h"

using namespace std;

void observer()
{
    // Person person = Person();
    Person person = Person("Bibilabu", {2026, 1, 1}, 0);

    // 或者手动通过Setter初始化/覆盖对象 person 成员值
    person
    // .setName("Timi")
    // .setBirthday({2026, 1, 1})
    // .setGender(0)
    .setId(440304202001010001);

    person.motto = "我是一个人";

    cout << "姓名: " << person.getName() << endl;
    cout << "生日: " << person.getBirthday() << endl;
    cout << "性别: " << person.getGender() << endl;
    cout << "身份证: " << person.getId() << endl;
    // cout << person.getAge() << endl;
    cout << "座右铭: " << person.motto << endl;
}

int main()
{
    // 强制控制台使用 UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // 让 cout 正确输出 UTF-8（关键）
    ios::sync_with_stdio(false);

    observer();

    return 0;
}