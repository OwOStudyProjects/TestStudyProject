/**
 * GPT 5.3 优化版
 * Author: GPT 5.3 & HanskiJay (Tommy131)
 * Time: 2026.04.05 17:14
 * Version 1.1
*/

#include <iostream>
#include <windows.h>
#include <vector>
#include "main.hpp"

using namespace std;

bool isValidName(const string &name);
bool isValidAge(int age);
bool isValidScore(float score);
bool inputStudentName(Student &s);
bool inputStudentAge(Student &s);
bool inputStudentScore(Student &s);
bool inputStudent(Student &s);
void displayAllStudents(const vector<Student> &v);

const string ERROR_PREFIX = "[ERROR] ";

/* ================= 工具函数 ================= */

/**
 * @brief 安全读取一行（禁止空输入）
 */
bool betterGetline(istream &input, string &str)
{
    getline(input, str);
    if (str.empty())
    {
        cout << ERROR_PREFIX << "不允许空输入！" << endl;
        return false;
    }
    return true;
}

/* ================= 校验函数 ================= */

bool isValidName(const string &name)
{
    if (name.length() > 20)
    {
        cout << ERROR_PREFIX << "名字长度过长！(len=" << name.length() << ")" << endl;
        return false;
    }
    return true;
}

bool isValidAge(int age)
{
    if (age < 0 || age > 150)
    {
        cout << ERROR_PREFIX << "年龄不在允许区间！(age=" << age << ")" << endl;
        return false;
    }
    return true;
}

bool isValidScore(float score)
{
    if (score < 0.0 || score > 100.0)
    {
        cout << ERROR_PREFIX << "成绩不在允许区间！(score=" << score << ")" << endl;
        return false;
    }
    return true;
}

/* ================= 输入函数 ================= */

bool inputStudentName(Student &s)
{
    string line;
    cout << "请输入学生姓名 (长度小于20个字符): ";

    if (!betterGetline(cin, line)) return false;

    if (line == "exit") return false;

    if (!isValidName(line)) return false;

    s.name = line;
    return true;
}

bool inputStudentAge(Student &s)
{
    string line;
    cout << "请输入学生 [" << s.name << "] 的年龄: ";

    if (!betterGetline(cin, line)) return false;

    try
    {
        int age = stoi(line);
        if (!isValidAge(age)) return false;

        s.age = age;
        return true;
    }
    catch (...)
    {
        cout << ERROR_PREFIX << "年龄输入无效！" << endl;
        return false;
    }
}

bool inputStudentScore(Student &s)
{
    string line;
    cout << "请输入学生 [" << s.name << "] 的成绩: ";

    if (!betterGetline(cin, line)) return false;

    try
    {
        float score = stof(line);
        if (!isValidScore(score)) return false;

        s.score = score;
        return true;
    }
    catch (...)
    {
        cout << ERROR_PREFIX << "成绩输入无效！" << endl;
        return false;
    }
}

/**
 * @brief 完整输入一个学生
 */
bool inputStudent(Student &s)
{
    if (!inputStudentName(s)) return false;
    if (!inputStudentAge(s)) return false;
    if (!inputStudentScore(s)) return false;

    cout << "已完成学生 [" << s.name << "] 的信息输入!" << endl << endl;
    return true;
}

/* ================= 输出函数 ================= */

void displayHeader()
{
    cout << left << setw(19) << "姓名"
         << left << setw(10) << "年龄"
         << left << setw(10) << "成绩"
         << endl;
}

void displayStudent(const Student &s)
{
    cout << left << setw(19) << s.name
         << left << setw(10) << s.age
         << left << setw(10) << fixed << setprecision(2) << s.score
         << endl;
}

void displayAllStudents(const vector<Student> &v)
{
    displayHeader();
    for (const auto &s : v)
    {
        displayStudent(s);
    }
    cout << endl;
}

/* ================= 主函数 ================= */

int main()
{
    vector<Student> students;
    const int MAX_COUNT = 5;

    // 强制控制台使用 UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // 让 cout 正确输出 UTF-8（关键）
    ios::sync_with_stdio(false);

    while (students.size() < MAX_COUNT)
    {
        Student s;

        if (!inputStudent(s))
        {
            cout << "输入失败，请重试。\n";
            continue;
        }

        students.push_back(s);
        displayAllStudents(students);
    }

    cout << "已达到最大输入数量，程序结束。" << endl;
    return 0;
}