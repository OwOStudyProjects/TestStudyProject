/**
 * Author: HanskiJay (Tommy131)
 * Time: 2026.04.05 16:38
 * Version 1.0
 */

#include <iostream>
#include <windows.h>
#include "main.hpp"
#include <vector>

void displayStudent(const Student &s)
{
    cout << left << setw(19) << s.name
         << left << setw(10) << s.age
         << left << setw(10) << fixed << setprecision(2) << s.score
         << endl;
}

bool betterGetline(istream &input, string &str)
{
    getline(input, str);
    if (str == "")
    {
        cout << "[ERROR] 不允许空输入！" << endl;
    }
    return str != "";
}

int main(void)
{
    const string prefix = "[ERROR] ";
    vector<Student> v_s{};

    int count = 0;
    string line;
    Student s;

    // 强制控制台使用 UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // 让 cout 正确输出 UTF-8（关键）
    ios::sync_with_stdio(false);

    while (count < 5)
    {
        try
        {
            cout << "请输入学生姓名 (长度小于20个字符): ";
            if (!betterGetline(cin, line))
                continue;

            if (line == "exit")
            {
                cout << "用户已终止数据输入！" << endl;
                break;
            }

            s.name = line;
            if (s.name.length() > 20)
            {
                cout << prefix << "名字长度过长！(len=" << s.name.length() << ")" << endl;
                return false;
            }
            cout << "已输入学生姓名: " << line << endl;

            cout << "请输入学生 [" << s.name << "] 的年龄 (0 <= age <= 150): ";
            // 使用 stringstream 或 stoi 将字符串转换为 int
            if (!betterGetline(cin, line))
                continue;

            s.age = stoi(line);
            if (s.age < 0 || s.age > 150)
            {
                cout << prefix << "年龄不在允许的区间内！(age=" << s.age << "); should be in interval [0;150]" << endl;
                return false;
            }
            cout << "已输入学生 [" << s.name << "] 的年龄: " << s.age << endl;

            cout << "请输入学生 [" << s.name << "] 的的成绩 (0 <= score <= 100): ";
            // 使用 stringstream 或 stof 将字符串转换为 float
            if (!betterGetline(cin, line))
                continue;

            s.score = stof(line);
            cout << "已输入学生 [" << s.name << "] 的成绩: " << s.score << endl;
            if (s.score < 0.0 || s.score > 100.0)
            {
                cout << prefix << "成绩不在允许的区间内！(score=" << s.score << "); should be in interval [0;100]" << endl;
                return false;
            }

            v_s.push_back(s);
            cout << "已完成学生学生 [" << s.name << "] 的信息输入!" << endl
                 << endl
                 << endl;
            count++; // count = count + 1; count += 1;

            cout << left << setw(19) << "姓名"
                 << left << setw(10) << "年龄"
                 << left << setw(10) << fixed << setprecision(1) << "成绩"
                 << endl;
            for (size_t i = 0; i < v_s.size(); i++)
            {
                displayStudent(v_s.at(i));
            }

            cout << endl
                 << endl;
        }
        catch (const exception &e)
        {
            cerr << "无效的输入，请重新输入。\n";
            continue;
        }
    }

    return 0;
}
