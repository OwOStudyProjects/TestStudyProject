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