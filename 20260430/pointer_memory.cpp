#include <iostream>
using namespace std;

// 打印分隔线
void line() {
    cout << "----------------------------------------\n";
}

// 打印栈变量信息
void printStack(const char* name, void* addr, const char* desc) {
    cout << "[Stack] " << name
         << " | 地址: " << addr
         << " | " << desc << endl;
}

// 打印堆块
void printHeap(int* ptr, int size, const char* name) {
    cout << "\n[Heap Block] " << name << " 起始地址: " << ptr << endl;
    for (int i = 0; i < size; i++) {
        cout << "  [" << i << "] 地址: " << (ptr + i)
             << " 值: " << *(ptr + i) << endl;
    }
}

// 第二层函数（制造栈帧）
void funcB() {
    int b1 = 100;
    int b2 = 200;

    cout << "\n===== 进入 funcB (栈更深) =====\n";
    printStack("b1", &b1, "int");
    printStack("b2", &b2, "int");

    line();
}

// 第一层函数
void funcA() {
    int a1 = 10;
    double a2 = 3.14;

    cout << "\n===== 进入 funcA =====\n";
    printStack("a1", &a1, "int");
    printStack("a2", &a2, "double");

    funcB(); // 再压一层栈

    line();
}

int main() {
    cout << "========= 内存可视化（增强版） =========\n";

    // ===== 栈区变量 =====
    int x = 1;
    int y = 2;
    double z = 9.9;

    int arr[3] = {10, 20, 30}; // 栈数组

    int* ptr1 = new int[4];
    int* ptr2 = new int;

    // 初始化堆
    for (int i = 0; i < 4; i++) ptr1[i] = i + 1;
    *ptr2 = 999;

    cout << "\n===== 主函数栈区 =====\n";
    printStack("x", &x, "int");
    printStack("y", &y, "int");
    printStack("z", &z, "double");

    printStack("arr[0]", &arr[0], "int");
    printStack("arr[1]", &arr[1], "int");
    printStack("arr[2]", &arr[2], "int");

    printStack("ptr1", &ptr1, "指针 -> 堆");
    printStack("ptr2", &ptr2, "指针 -> 堆");

    line();

    // ===== 堆区 =====
    cout << "\n===== 堆区 =====\n";
    printHeap(ptr1, 4, "ptr1");
    printHeap(ptr2, 1, "ptr2");

    line();

    // ===== 调用函数（增加栈层）=====
    funcA();

    // ===== CLI结构图 =====
    cout << "\n===== 简化结构图 =====\n";

    cout << "\nStack (向下 ↓)\n";
    cout << "--------------------------------\n";
    cout << "| funcB: b2, b1               |\n";
    cout << "| funcA: a2, a1               |\n";
    cout << "| main: ptr2 -> " << ptr2 << " |\n";
    cout << "| main: ptr1 -> " << ptr1 << " |\n";
    cout << "| main: arr[2], arr[1], arr[0]|\n";
    cout << "| main: z, y, x               |\n";
    cout << "--------------------------------\n";

    cout << "\nHeap (向上 ↑)\n";
    cout << "--------------------------------\n";
    cout << ptr2 << " : " << *ptr2 << endl;
    for (int i = 0; i < 4; i++) {
        cout << (ptr1 + i) << " : " << ptr1[i] << endl;
    }
    cout << "--------------------------------\n";

    // 释放
    delete[] ptr1;
    delete ptr2;

    return 0;
}