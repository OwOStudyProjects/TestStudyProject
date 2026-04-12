/**
 * Author: HanskiJay (Tommy131)
 * Time: 2026.04.12 23:38
 * Version 1.0
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <windows.h>

#include "main.hpp"

/*-------------------------------------------------------------------------------------------------*/
// Source - https://stackoverflow.com/a/217605
// Posted by Evan Teran, modified by community. See post 'Timeline' for change history
// Retrieved 2026-04-12, License - CC BY-SA 4.0

// Trim from the start (in place)
inline void ltrim(std::string &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch)
                                    { return !std::isspace(ch); }));
}

// Trim from the end (in place)
inline void rtrim(std::string &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch)
                         { return !std::isspace(ch); })
                .base(),
            s.end());
}
/*-------------------------------------------------------------------------------------------------*/

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

void outputTableHeader()
{
    cout << left << setw(19) << "姓名"
         << left << setw(10) << "年龄"
         << left << setw(10) << fixed << setprecision(1) << "成绩"
         << endl;
}

int main(void)
{
    const string prefix = "[ERROR] ";
    vector<Student> v_s{};

    int count = 0;
    string inputLine;
    Student s;

    // 强制控制台使用 UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // 让 cout 正确输出 UTF-8（关键）
    ios::sync_with_stdio(false);

    string selected;
    bool selection = false;
    // 是否从文件加载？
    cout << "是否从文件加载？ (Y/N，默认 Y)" << endl;
    getline(cin, selected);

    selected = tolower(selected[0]);
    // 过滤掉了左右两侧的空格
    ltrim(selected);
    rtrim(selected);

    selection = (selected == "") || (selected == "y");

    cout << "当前模式: " << (selection ? "从文件加载数据" : "仅输出数据") << endl;

    /* [读取文件-START]-------------------------------------------------------- */
    // 1. 创建输入流对象并打开文件
    // std::ios::binary 以二进制方式读取文件
    ifstream readFile("./students.txt", ios::binary);

    // 阻止非法操作
    if (!readFile.is_open())
        return -1;

    // 当前整行 (原始文件行)
    string line;
    // 输出缓冲区
    vector<string> outputBuffer;
    // 行计数器
    int linesCount = 0;

    // 第一次循环: 写入每行数据到输出缓冲区
    while (getline(readFile, line))
    {
        outputBuffer.push_back(line);
        linesCount++;
    }

    if (linesCount > 0)
    {
        cout << "已加载到 (" << linesCount << ") 条数据。最后3条数据：" << endl;
        // 输出表标题
        outputTableHeader();

        // 分割过后的单个元素
        string element;

        // 再次循环读取原始行数
        for (int i = 0; i < linesCount; i++)
        {
            line = outputBuffer.at(i);
            istringstream ss(line);

            // 解析分割行
            getline(ss, element, ' ');
            s.name = element;
            getline(ss, element, ' ');
            s.age = stoi(element);
            getline(ss, element, ' ');
            s.score = stof(element);

            if (selection)
            {
                // 把数据写入到向量对象 vector<Student> 中
                v_s.push_back(s);
            }

            if (i >= linesCount - 3 && i <= linesCount)
            {
                displayStudent(s);
            }
        }
        cout << endl;
    }
    /* [读取文件-END]---------------------------------------------------------- */

    /* [写入文件-START]-------------------------------------------------------- */
    // 1. 创建输出流对象并打开文件（如果不存在则创建，默认覆盖模式）
    // std::ios::binary 以二进制方式读取文件
    // std::ios::app    使用追加模式写入文件 (append)
    ofstream file("./students.txt", ios::binary | ios::app);

    // 阻止非法操作
    if (!file.is_open())
        return -1;

    while (count < 5)
    {
        try
        {
            cout << "请输入学生姓名 (长度小于20个字符): ";
            if (!betterGetline(cin, inputLine))
                continue;

            if (inputLine == "exit")
            {
                cout << "用户已终止数据输入！" << endl;
                break;
            }

            s.name = inputLine;
            if (s.name.length() > 20)
            {
                cout << prefix << "名字长度过长！(len=" << s.name.length() << ")" << endl;
                return false;
            }
            cout << "已输入学生姓名: " << inputLine << endl;

            cout << "请输入学生 [" << s.name << "] 的年龄 (0 <= age <= 150): ";
            if (!betterGetline(cin, inputLine))
                continue;

            // 使用 stringstream 或 stoi 将字符串转换为 int
            s.age = stoi(inputLine);
            if (s.age < 0 || s.age > 150)
            {
                cout << prefix << "年龄不在允许的区间内！(age=" << s.age << "); should be in interval [0;150]" << endl;
                return false;
            }
            cout << "已输入学生 [" << s.name << "] 的年龄: " << s.age << endl;

            cout << "请输入学生 [" << s.name << "] 的的成绩 (0 <= score <= 100): ";
            if (!betterGetline(cin, inputLine))
                continue;

            // 使用 stringstream 或 stof 将字符串转换为 float
            s.score = stof(inputLine);
            cout << "已输入学生 [" << s.name << "] 的成绩: " << s.score << endl;
            if (s.score < 0.0 || s.score > 100.0)
            {
                cout << prefix << "成绩不在允许的区间内！(score=" << s.score << "); should be in interval [0;100]" << endl;
                return false;
            }

            // 将当前的学生结构体压入 vector<Student> 向量对象中
            v_s.push_back(s);

            // 将当前的学生结构体写入到文件
            file << s.name << ' ' << s.age << ' ' << fixed << setprecision(2) << s.score << '\n';

            cout << "已完成学生学生 [" << s.name << "] 的信息输入!" << endl
                 << endl
                 << endl;
            count++; // count = count + 1; count += 1;

            outputTableHeader();
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

    // 4. 关闭文件
    file.close();
    /* [写入文件-END]-------------------------------------------------------- */

    return 0;
}
