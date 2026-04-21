/**
 * Author: HanskiJay (Tommy131)
 * Time: 2026.04.05 16:38
 * Version 1.0
 */
#include <string>
#include <iomanip>

using namespace std;

// 定义一个名称为 Student 的结构体, 使用 typedef 简化类型定义
typedef struct Student
{
    string name;
    int age;
    float score;

} Student;

bool betterGetline(istream &input, string &str);

// 规范化输出学生表格排版
void displayStudent(const Student &s);

// 规范化输出学生表格标题
void outputTableHeader();

// 来自谷歌搜索结果: 判断是否是整型
bool isInteger(const std::string &s);

// From StackOverFlow: https://stackoverflow.com/questions/997946/how-can-i-get-current-time-and-date-in-c
// Get the current date/time. The format is YYYY-MM-DD.HH:mm:ss
const std::string currentDateTime();

// 问询控制台写入模式
int AskMode(int &mode);

// 备份文件
void backupFile(const string &fileName);