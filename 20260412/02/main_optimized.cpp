/**
 * GPT 5.3 优化版
 * Author: GPT 5.3 & HanskiJay (Tommy131)
 * Time: 2026.04.12 23:38
 * Version: 1.1 (优化 + 注释增强版)
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <windows.h>

#include "main.hpp"

using namespace std;

/*-------------------------------------------------------------------------------------------------
字符串去空格工具函数（来源 StackOverflow）
作用：去除字符串左右两侧的空白字符（空格、换行等）
Source - https://stackoverflow.com/a/217605
Posted by Evan Teran, modified by community. See post 'Timeline' for change history
Retrieved 2026-04-12, License - CC BY-SA 4.0
-------------------------------------------------------------------------------------------------*/

// 去除左空格
void ltrim(string &s)
{
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch)
                               { return !isspace(ch); }));
}

// 去除右空格
void rtrim(string &s)
{
    s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch)
                    { return !isspace(ch); })
                .base(),
            s.end());
}

// 安全输入
bool betterGetline(string &str)
{
    getline(cin, str);
    if (str.empty())
    {
        cout << "[ERROR] 不允许空输入！" << endl;
        return false;
    }
    return true;
}

/*==================== 输出模块 ====================*/

// 表头
void printHeader()
{
    cout << left << setw(19) << "姓名"
         << setw(10) << "年龄"
         << setw(10) << "成绩" << endl;
}

// 打印单个学生
void printStudent(const Student &s)
{
    cout << left << setw(19) << s.name
         << setw(10) << s.age
         << setw(10) << fixed << setprecision(2) << s.score
         << endl;
}

// 打印所有学生
void printStudents(const vector<Student> &v)
{
    printHeader();
    for (const auto &s : v)
        printStudent(s);
}

/*==================== 文件模块 ====================*/

// 从文件读取
void loadFromFile(vector<Student> &v)
{
    ifstream file("./students.txt");
    if (!file.is_open())
    {
        cerr << "[ERROR] 文件打开失败" << endl;
        return;
    }

    string line;
    vector<Student> temp;

    while (getline(file, line))
    {
        istringstream ss(line);
        Student s;

        ss >> s.name >> s.age >> s.score;
        temp.push_back(s);
    }

    file.close();

    if (!temp.empty())
    {
        cout << "已加载 " << temp.size() << " 条数据，最后3条：" << endl;
        printHeader();

        /*
        使用 max(0, (int)temp.size() - 3) 是为了：
        ✅ 防止负数索引
        ✅ 防止 unsigned 类型溢出
        ✅ 保证循环安全
        */
        int start = max(0, (int)temp.size() - 3);
        for (size_t i = start; i < temp.size(); i++)
            printStudent(temp[i]);
    }

    v = temp; // 赋值给主数据
}

// 写入文件（追加）
void appendToFile(const Student &s)
{
    ofstream file("./students.txt", ios::app);
    if (!file.is_open())
    {
        cerr << "[ERROR] 写入文件失败" << endl;
        return;
    }

    file << s.name << " "
         << s.age << " "
         << fixed << setprecision(2)
         << s.score << "\n";

    file.close();
}

/*==================== 输入模块 ====================*/

// 输入一个学生（核心逻辑拆出来）
bool inputStudent(Student &s)
{
    string input;

    cout << "请输入姓名: ";
    if (!betterGetline(input))
        return false;

    if (input == "exit")
        return false;

    if (input.length() > 20)
    {
        cout << "[ERROR] 名字过长" << endl;
        return false;
    }
    s.name = input;

    cout << "请输入年龄: ";
    if (!betterGetline(input))
        return false;

    try
    {
        s.age = stoi(input);
    }
    catch (...)
    {
        cout << "[ERROR] 年龄格式错误" << endl;
        return false;
    }

    if (s.age < 0 || s.age > 150)
    {
        cout << "[ERROR] 年龄非法" << endl;
        return false;
    }

    cout << "请输入成绩: ";
    if (!betterGetline(input))
        return false;

    try
    {
        s.score = stof(input);
    }
    catch (...)
    {
        cout << "[ERROR] 成绩格式错误" << endl;
        return false;
    }

    if (s.score < 0 || s.score > 100)
    {
        cout << "[ERROR] 成绩非法" << endl;
        return false;
    }

    return true;
}

/*==================== 主函数 ====================*/

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    ios::sync_with_stdio(false);

    vector<Student> students;

    /*---------- 选择模式 ----------*/
    string selected;
    cout << "是否从文件加载？(Y/N 默认Y): ";
    getline(cin, selected);

    ltrim(selected);
    rtrim(selected);

    char choice = selected.empty() ? 'y' : tolower(selected[0]);

    if (choice == 'y')
        loadFromFile(students);

    /*---------- 输入循环 ----------*/
    int count = 0;

    while (count < 5)
    {
        Student s;

        if (!inputStudent(s))
            continue;

        students.push_back(s);
        appendToFile(s);

        cout << "录入成功！当前数据：" << endl;
        printStudents(students);

        count++;
    }

    return 0;
}