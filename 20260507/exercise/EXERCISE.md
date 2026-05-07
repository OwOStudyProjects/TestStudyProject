# C++ 基类入门练习文本

## 练习背景

在现实软件开发中，我们经常需要对一类具有相似属性和行为的事物进行建模。例如，管理一个小型图书馆时，我们可能有不同类型的“文档”——书籍、杂志、报纸，它们都具有**标题**和**编号**等公共属性，但具体行为可能有所不同。

在 C++ 中，我们可以通过 **基类（Base Class）** 来定义这些公共属性和行为，再通过 **派生类（Derived Class）** 来扩展特殊功能。这种方式可以让代码结构清晰、易扩展，同时符合面向对象的开发思想。

---

## 练习任务

请你用 C++ 编写一个简单的面向对象程序，实现以下要求：

### 1. 定义基类 `Document`

* 成员属性（private 或 protected）：

  * `title`（字符串类型）
  * `id`（整数类型）
* 成员函数：

  * 构造函数：初始化 `title` 和 `id`
  * `printInfo()`：输出文档的标题和编号

### 2. 定义派生类 `Book`

* 继承自 `Document`
* 新增属性：

  * `author`（字符串类型）
* 新增函数：

  * 构造函数：初始化 `title`、`id` 和 `author`
  * 重写 `printInfo()`：除了输出标题和编号，还输出作者姓名

### 3. 主函数操作

* 创建一个 `Book` 对象
* 调用 `printInfo()` 输出信息

---

## 练习示例（提示）

你可以参考下面思路，但不要直接复制：

```cpp
#include <iostream>
#include <string>
using namespace std;

// 基类
class Document {
protected:
    string title;
    int id;
public:
    Document(string t, int i) : title(t), id(i) {}
    void printInfo() {
        cout << "Title: " << title << ", ID: " << id << endl;
    }
};

// 派生类
class Book : public Document {
private:
    string author;
public:
    Book(string t, int i, string a) : Document(t, i), author(a) {}
    void printInfo() { // 重写
        Document::printInfo();
        cout << "Author: " << author << endl;
    }
};

int main() {
    Book b("C++入门指南", 101, "张三");
    b.printInfo();
    return 0;
}
```

---

## 练习目标

1. 理解 **基类和派生类的定义语法**
2. 学会 **成员继承和访问控制（private/protected/public）**
3. 掌握 **构造函数初始化列表**
4. 学会 **重写基类方法**
5. 理解 **对象创建和函数调用**

---

## 拓展练习（选做）

1. 添加一个派生类 `Magazine`，新增属性 `issueNumber`（期号）并重写 `printInfo()`。
2. 在主函数中创建一个 `Document*` 指针，指向 `Book` 或 `Magazine` 对象，并尝试通过指针调用 `printInfo()`，理解多态的初步概念。
3. 尝试将 `printInfo()` 改为 **虚函数**（`virtual`）观察多态效果。
