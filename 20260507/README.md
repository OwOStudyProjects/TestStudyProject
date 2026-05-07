# 2026.05.07 会议概要

## 1. C++ 类与对象

* **类（Class）**：面向对象编程（OOP）的核心，用于封装数据和操作数据的方法。

  ```cpp
  class Person {
      std::string name;
      int age;
  public:
      void setName(const std::string& newName);
      void setAge(int newAge);
  };
  ```

* **对象（Object）**：类的实例，每个对象拥有独立的属性值。
* **访问控制**：`public`（可访问）、`private`（仅类内访问）、`protected`（继承可访问）。
* **方法返回引用**：

  * 使用 `Person&` 返回对象本身的引用，可支持链式调用，避免拷贝，提高性能。
  * 示例：

    ```cpp
    Person& Person::setGender(int g) {
        gender = g;
        return *this;
    }
    ```

  * 与值返回（`Person`）对比：值返回会生成临时对象，不利于链式调用，效率低。

---

## 2. 构造函数与析构函数

* **构造函数（Constructor）**：

  * 自动在对象创建时调用，用于初始化对象成员。
  * 支持重载，允许不同方式初始化对象。
  * 示例：

    ```cpp
    Person() { age = 0; }
    Person(const std::string& n, int a) : name(n), age(a) {}
    ```

* **析构函数（Destructor）**：

  * 对象销毁时自动调用，用于资源释放（如动态分配内存）。
  * 格式：`~ClassName() { /* cleanup */ }`

---

## 3. C++ 中整数类型

* **int**：

  * 32 位环境下占 4 字节，范围：`-2,147,483,648 ~ 2,147,483,647`。
  * 使用 `<climits>` 可以获取平台相关的 `INT_MAX`、`INT_MIN`。
* **uint32_t**：

  * 无符号 32 位整数，保证跨平台占 4 字节，范围：`0 ~ 4,294,967,295`。
  * 适合需要固定宽度整数的场景（网络协议、二进制文件等）。

  ```cpp
  #include <cstdint>
  uint32_t n = 4294967295U;
  ```

* **long long**：

  * 64 位整数，范围：`-2^63 ~ 2^63-1`。
* **注意**：整型大小可能因平台和编译器而异，使用标准宏和固定宽度类型更安全。

---

## 4. 命名规范：驼峰命名法（Camel Case）

* **小驼峰（lowerCamelCase）**：第一个单词首字母小写，其余单词首字母大写。

  * 用于变量、函数：`firstName, sendEmail()`
* **大驼峰/帕斯卡命名法（UpperCamelCase / PascalCase）**：每个单词首字母大写。

  * 用于类、命名空间、属性：`UserAccount, FirstName`
* **优点**：

  * 减少下划线，缩短标识符长度，提高可读性。
  * 与蛇形命名法（snake_case）对比，代码更紧凑整洁。

---

## 5. 面向对象编程（OOP）核心概念

* **封装（Encapsulation）**：

  * 数据与方法封装在类中，隐藏实现细节，仅暴露必要接口。

* **继承（Inheritance）**：

  * 子类继承父类特性和行为，减少重复代码，形成层级结构。

* **多态（Polymorphism）**：

  * 同一接口可被不同对象以不同方式实现，提高灵活性。

* **抽象（Abstraction）**：

  * 隐藏复杂实现逻辑，仅暴露核心功能。

* **优势**：

  * 易维护、易扩展、模块化、重用性高。
  * 适合复杂系统设计，与面向过程（Procedural）相比，更关注对象间的协作和消息传递。

---

## 6. 常用 C 函数 `sprintf`

* 用于格式化字符串，将数据写入字符数组：

  ```cpp
  char buffer[50];
  int age = 25;
  sprintf(buffer, "Age: %d", age);
  ```

* 注意安全性：容易造成缓冲区溢出，C++ 中推荐使用 `std::ostringstream` 或 `snprintf`。

## 7. 参考网站

* <https://www.runoob.com/cplusplus/cpp-classes-objects.html>
* <https://www.runoob.com/cplusplus/cpp-constructor-destructor.html>
* <https://cplusplus.com/reference/cstdio/sprintf/>
