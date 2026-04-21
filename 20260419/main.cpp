/**
 * Author: HanskiJay (Tommy131)
 * Time: 2026.04.12 23:38
 * Version 1.2 (Bug Fixed)
 *
 * 功能说明：
 *   - 从文件 students.txt 中读取学生信息（姓名、年龄、成绩）
 *   - 支持覆盖模式（Mode 1）或追加模式（Mode 2）写入新数据
 *   - 每次运行前自动备份原始文件
 *   - 最多支持输入5名学生，输入 "exit" 可提前退出
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

// 去除字符串左侧（开头）的空白字符（原地修改）
inline void ltrim(std::string &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch)
                                    { return !std::isspace(ch); }));
}

// 去除字符串右侧（末尾）的空白字符（原地修改）
inline void rtrim(std::string &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch)
                         { return !std::isspace(ch); })
                .base(),
            s.end());
}

// 判断字符串是否可以被完整解析为整数（支持正负号）
bool isInteger(const std::string &s)
{
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
        return false;
    char *p;
    strtol(s.c_str(), &p, 10);
    return (*p == 0);
}

// 返回当前日期字符串，格式为 "YYYYMMDD"，用于生成备份文件名
const std::string currentDateTime()
{
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y%m%d", &tstruct);
    return buf;
}
/*-------------------------------------------------------------------------------------------------*/

// 以格式化方式输出单个学生的信息（姓名、年龄、成绩）
void displayStudent(const Student &s)
{
    cout << left << setw(19) << s.name
         << left << setw(10) << s.age
         << left << setw(10) << fixed << setprecision(2) << s.score
         << endl;
}

/**
 * 封装 getline，拒绝空输入
 * @return 输入非空则返回 true，否则输出错误提示并返回 false
 */
bool betterGetline(istream &input, string &str)
{
    getline(input, str);
    if (str.empty())
    {
        cout << "[ERROR] 不允许空输入！" << endl;
    }
    return !str.empty();
}

// 输出学生信息表格的列标题行
void outputTableHeader()
{
    cout << left << setw(19) << "姓名"
         << left << setw(10) << "年龄"
         << left << setw(10) << fixed << setprecision(1) << "成绩"
         << endl;
}

/**
 * 打印并规范化写入模式
 * @param mode  传入写入模式（1=覆盖, 2=追加），非法值自动重置为 1
 * @return      处理后的 mode 值
 */
int AskMode(int &mode)
{
    switch (mode)
    {
    case 1:
        cout << "Mode Selection: 1 (Overwrite)" << endl;
        break;
    case 2:
        cout << "Mode Selection: 2 (Append)" << endl;
        break;
    default:
        cout << "[WARN] 非法模式，已自动重置为默认模式 1 (Overwrite)" << endl;
        mode = 1;
        break;
    }
    return mode;
}

// 将 fileName 备份为带日期后缀的副本，例如 students_backup_20260412.txt
void backupFile(const string &fileName)
{
    const string backupName = "students_backup_" + currentDateTime() + ".txt";
    std::ifstream src(fileName, std::ios::binary);
    std::ofstream dst(backupName, std::ios::binary);

    cout << "[FileBackuper] Backup file to: " << backupName << endl;

    // 利用流缓冲区直接复制文件内容
    dst << src.rdbuf();
}

/**
 * 从已解析的行缓冲区中加载学生数据到向量，并打印最后 3 条记录
 * @param outputBuffer  原始文件按行存储的字符串列表
 * @param v_s           目标学生向量（若 loadData 为 true 则写入）
 * @param loadData      是否将数据载入内存
 */
void loadStudentsFromBuffer(const vector<string> &outputBuffer,
                            vector<Student> &v_s,
                            bool loadData)
{
    int linesCount = static_cast<int>(outputBuffer.size());

    if (linesCount <= 0)
        return;

    cout << "已加载到 (" << linesCount << ") 条数据。最后3条数据：" << endl;
    outputTableHeader();

    for (int i = 0; i < linesCount; i++)
    {
        string line = outputBuffer[i];
        istringstream ss(line);
        string element;
        Student s;

        // 按空格依次解析姓名、年龄、成绩
        getline(ss, element, ' ');
        s.name = element;
        getline(ss, element, ' ');
        s.age = stoi(element);
        getline(ss, element, ' ');
        s.score = stof(element);

        // 根据选项决定是否加载到内存中
        if (loadData)
        {
            v_s.push_back(s);
        }

        // 只显示最后 3 条记录
        if (i >= linesCount - 3)
        {
            displayStudent(s);
        }
    }

    cout << endl;
}

/**
 * 交互式录入一名学生信息，验证并写入内存
 * 注意：不再在此函数内写文件，统一由 main 在结束后全量写入
 * @param v_s           目标学生向量
 * @param studentIndex  当前是第几位学生（用于提示语，从 1 开始）
 * @return              成功录入返回 true，用户输入 exit 返回 false
 */
bool inputOneStudent(vector<Student> &v_s, int studentIndex)
{
    const string prefix = "[ERROR] ";
    string inputLine;
    Student s;

    // ---------- 录入姓名 ----------
    // 提示语包含序号，符合题目"请输入第X位学生的姓名"要求
    cout << "请输入第 " << studentIndex << " 位学生的姓名 (长度不超过20个字符，输入 exit 退出): ";
    if (!betterGetline(cin, inputLine))
        return true; // 空输入，跳过本次但不退出

    if (inputLine == "exit")
    {
        cout << "用户已终止数据输入！" << endl;
        return false; // 通知调用方退出循环
    }

    s.name = inputLine;
    if (s.name.length() > 20)
    {
        cout << prefix << "名字长度过长！(len=" << s.name.length() << ")，请重新输入。" << endl;
        return true; // 验证失败，重新输入
    }

    // ---------- 录入年龄 ----------
    cout << "请输入第 " << studentIndex << " 位学生 [" << s.name << "] 的年龄 (0 <= age <= 150): ";
    if (!betterGetline(cin, inputLine))
        return true;

    s.age = stoi(inputLine);
    if (s.age < 0 || s.age > 150)
    {
        cout << prefix << "年龄不在允许区间内！(age=" << s.age << "); 应在 [0, 150]" << endl;
        return true;
    }

    // ---------- 录入成绩 ----------
    cout << "请输入第 " << studentIndex << " 位学生 [" << s.name << "] 的成绩 (0.0 <= score <= 100.0): ";
    if (!betterGetline(cin, inputLine))
        return true;

    s.score = stof(inputLine);
    if (s.score < 0.0f || s.score > 100.0f)
    {
        cout << prefix << "成绩不在允许区间内！(score=" << s.score << "); 应在 [0, 100]" << endl;
        return true;
    }

    // ---------- 写入内存 ----------
    v_s.push_back(s);

    cout << "已完成第 " << studentIndex << " 位学生 [" << s.name << "] 的信息录入！\n"
         << endl;

    // 每次录入后实时输出当前所有学生列表
    outputTableHeader();
    for (const auto &stu : v_s)
    {
        displayStudent(stu);
    }
    cout << endl;

    return true; // 继续录入
}

// ============================================================
//  程序入口
// ============================================================
int main(int argc, char *argv[])
{
    // ---- 强制控制台使用 UTF-8，确保中文正常显示 ----
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    ios::sync_with_stdio(false); // 禁用 C / C++ 流同步，提升输出性能

    /* ---- 解析写入模式 ------------------------------------------ */
    int fileWriteMode;

    cout << "Parameter: " << argc << endl;

    if (argc == 1)
    {
        // 无命令行参数时，交互式询问用户
        cout << "[Mode 1] Overwrite data file\n"
             << "[Mode 2] Append to last line\n"
             << "Please choose [1 | 2] to confirm (default 1): ";

        string tmp;
        cin >> tmp;
        cin.ignore(); // 消耗 cin >> 残留的换行符，避免后续 getline 读到空行

        if (!isInteger(tmp))
        {
            cerr << "[Error] 无效的输入，程序终止。" << endl;
            return EXIT_FAILURE;
        }

        fileWriteMode = stoi(tmp);
    }
    else
    {
        // 通过命令行参数传入模式
        fileWriteMode = stoi(argv[1]);
    }

    AskMode(fileWriteMode); // 打印并规范化模式

    /* ---- 询问是否从文件加载已有数据 ------------------------------ */
    string selected;
    cout << "是否从文件加载已有数据？(Y/N，默认 Y): " << endl;
    getline(cin, selected);

    ltrim(selected);
    rtrim(selected);

    // 将首字符转为小写进行比较；空输入视为 'y'
    bool loadFromFile = selected.empty() || (tolower(selected[0]) == 'y');
    cout << "当前模式: " << (loadFromFile ? "从文件加载数据" : "仅输出数据") << endl;

    /* ---- 读取原始文件 ------------------------------------------- */
    const string DATA_FILE = "./students.txt";

    // [修复2] 文件不存在时自动创建空文件，而非报错退出
    {
        // 尝试以读模式打开，若失败则说明文件不存在，用 ofstream 创建之
        ifstream checkFile(DATA_FILE);
        if (!checkFile.is_open())
        {
            cout << "[INFO] 数据文件不存在，已自动创建：" << DATA_FILE << endl;
            ofstream createFile(DATA_FILE);
            if (!createFile.is_open())
            {
                cerr << "[ERROR] 无法创建数据文件：" << DATA_FILE << endl;
                return EXIT_FAILURE;
            }
            createFile.close();
        }
    }

    // 在任何写操作之前先备份（文件已确保存在）
    backupFile(DATA_FILE);

    // 打开文件进行读取，将内容逐行存入缓冲区
    vector<string> outputBuffer;
    {
        ifstream readFile(DATA_FILE, ios::binary);
        if (!readFile.is_open())
        {
            cerr << "[ERROR] 无法打开数据文件：" << DATA_FILE << endl;
            return EXIT_FAILURE;
        }

        string line;
        while (getline(readFile, line))
        {
            if (!line.empty()) // 跳过空行
                outputBuffer.push_back(line);
        }
        readFile.close();
    }

    // 内存中的学生列表
    vector<Student> v_s;

    // 解析缓冲区，可选地将历史数据载入 v_s
    loadStudentsFromBuffer(outputBuffer, v_s, loadFromFile);

    // 覆盖模式：清空内存中从文件加载的旧数据，仅保留本次新录入的数据
    if (fileWriteMode == 1)
    {
        v_s.clear();
        cout << "[FileMode] 覆盖模式：历史数据已清除，将只保存本次录入的数据。" << endl;
    }
    else
    {
        cout << "[FileMode] 追加模式：新数据将追加到历史数据之后。" << endl;
    }

    /* ---- 交互式录入新数据 --------------------------------------- */
    // 最多录入 5 名学生；studentIndex 为全局序号（含已加载的历史数据）
    const int MAX_NEW_STUDENTS = 5;
    int newCount = 0; // 本次新录入的数量

    while (newCount < MAX_NEW_STUDENTS)
    {
        // studentIndex = 已在内存中的总数 + 1，给用户连续的序号感知
        int studentIndex = static_cast<int>(v_s.size()) + 1;

        try
        {
            size_t sizeBefore = v_s.size();
            bool continueInput = inputOneStudent(v_s, studentIndex);

            if (!continueInput)
                break; // 用户输入 exit，退出循环

            // 只有向量真正增长，才视为成功录入一条
            if (v_s.size() > sizeBefore)
                newCount++;
        }
        catch (const exception &e)
        {
            // 捕获 stoi / stof 等转换异常，提示用户重新输入
            cerr << "[EXCEPTION] 无效的输入，请重新输入。(" << e.what() << ")\n";
        }
    }

    /* ---- [修复3] 退出前全量覆盖写入 ----------------------------- */
    // 无论是覆盖模式还是追加模式，最终都将内存中的完整 v_s 全量写入文件
    // 使用 trunc 模式打开，确保旧内容被完全清除后重新写入
    {
        ofstream file(DATA_FILE, ios::binary | ios::trunc);
        if (!file.is_open())
        {
            cerr << "[ERROR] 无法打开数据文件用于写入：" << DATA_FILE << endl;
            return EXIT_FAILURE;
        }

        for (const auto &stu : v_s)
        {
            file << stu.name << ' ' << stu.age << ' '
                 << fixed << setprecision(2) << stu.score << '\n';
        }

        file.close();
        cout << "[INFO] 已将全部 " << v_s.size() << " 条数据写入文件：" << DATA_FILE << endl;
    }

    return EXIT_SUCCESS;
}