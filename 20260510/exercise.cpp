#include <iostream>
#include <string>
using namespace std;

/* =========================================================
   第一部分：Person 基类
   ========================================================= */
class Person {
private:
    string name;
    string birthday;

public:
    // 带参构造函数
    Person(string name, string birthday) {
        this->name     = name;
        this->birthday = birthday;
    }

    // --- Setter ---
    void setName(string name)         { this->name     = name; }
    void setBirthday(string birthday) { this->birthday = birthday; }

    // --- Getter ---
    string getName()     { return name; }
    string getBirthday() { return birthday; }

    // 虚函数：允许派生类重写，支持多态
    virtual void printInfo() {
        cout << "姓名：" << name << endl;
        cout << "生日：" << birthday << endl;
    }

    // 虚析构函数（使用多态时的良好习惯）
    virtual ~Person() {}
};


/* =========================================================
   第二部分：Student 派生类（学生）
   ========================================================= */
class Student : public Person {
private:
    string studentId;   // 学号
    string major;       // 专业
    double gpa;         // 绩点

public:
    Student(string name, string birthday,
            string studentId, string major, double gpa)
        : Person(name, birthday) {
        this->studentId = studentId;
        this->major     = major;
        this->gpa       = gpa;
    }

    // --- Setter ---
    void setStudentId(string id)  { this->studentId = id; }
    void setMajor(string major)   { this->major     = major; }
    void setGpa(double gpa)       { this->gpa       = gpa; }

    // --- Getter ---
    string getStudentId() { return studentId; }
    string getMajor()     { return major; }
    double getGpa()       { return gpa; }

    void printInfo() override {
        Person::printInfo();          // 先打印父类信息
        cout << "学号：" << studentId << endl;
        cout << "专业：" << major     << endl;
        cout << "绩点：" << gpa       << endl;
    }
};


/* =========================================================
   第三部分：Teacher 派生类（老师）
   ========================================================= */
class Teacher : public Person {
private:
    string teacherId;   // 工号
    string department;  // 院系
    string title;       // 职称（讲师 / 副教授 / 教授）

public:
    Teacher(string name, string birthday,
            string teacherId, string department, string title)
        : Person(name, birthday) {
        this->teacherId   = teacherId;
        this->department  = department;
        this->title       = title;
    }

    // --- Setter ---
    void setTeacherId(string id)      { this->teacherId  = id; }
    void setDepartment(string dept)   { this->department = dept; }
    void setTitle(string title)       { this->title      = title; }

    // --- Getter ---
    string getTeacherId()  { return teacherId; }
    string getDepartment() { return department; }
    string getTitle()      { return title; }

    void printInfo() override {
        Person::printInfo();
        cout << "工号：" << teacherId  << endl;
        cout << "院系：" << department << endl;
        cout << "职称：" << title      << endl;
    }
};


/* =========================================================
   第四部分：TeachingAssistant 派生类（助教）
   虚继承解决菱形继承问题：
       Person
      /      \
  Student  Teacher
      \      /
    TeachingAssistant
   ========================================================= */

// 使用虚继承，确保 Person 只有一份副本
class StudentV : virtual public Person {
private:
    string studentId;
    string major;
    double gpa;

public:
    StudentV(string name, string birthday,
             string studentId, string major, double gpa)
        : Person(name, birthday) {
        this->studentId = studentId;
        this->major     = major;
        this->gpa       = gpa;
    }

    void setStudentId(string id) { this->studentId = id; }
    void setMajor(string major)  { this->major     = major; }
    void setGpa(double gpa)      { this->gpa       = gpa; }

    string getStudentId() { return studentId; }
    string getMajor()     { return major; }
    double getGpa()       { return gpa; }

    virtual void printInfo() override {
        Person::printInfo();
        cout << "学号：" << studentId << endl;
        cout << "专业：" << major     << endl;
        cout << "绩点：" << gpa       << endl;
    }
};

class TeacherV : virtual public Person {
private:
    string teacherId;
    string department;
    string title;

public:
    TeacherV(string name, string birthday,
             string teacherId, string department, string title)
        : Person(name, birthday) {
        this->teacherId  = teacherId;
        this->department = department;
        this->title      = title;
    }

    void setTeacherId(string id)    { this->teacherId  = id; }
    void setDepartment(string dept) { this->department = dept; }
    void setTitle(string title)     { this->title      = title; }

    string getTeacherId()  { return teacherId; }
    string getDepartment() { return department; }
    string getTitle()      { return title; }

    virtual void printInfo() override {
        Person::printInfo();
        cout << "工号：" << teacherId  << endl;
        cout << "院系：" << department << endl;
        cout << "职称：" << title      << endl;
    }
};

class TeachingAssistant : public StudentV, public TeacherV {
private:
    string courseAssigned;  // 负责课程

public:
    // 虚继承时，最底层派生类必须直接调用虚基类的构造函数
    TeachingAssistant(string name, string birthday,
                      string studentId, string major, double gpa,
                      string teacherId, string department, string title,
                      string courseAssigned)
        : Person(name, birthday),
          StudentV(name, birthday, studentId, major, gpa),
          TeacherV(name, birthday, teacherId, department, title) {
        this->courseAssigned = courseAssigned;
    }

    void setCourseAssigned(string course) { this->courseAssigned = course; }
    string getCourseAssigned()            { return courseAssigned; }

    void printInfo() override {
        // 手动调用两个父类的信息段（跳过重复的 Person 部分）
        Person::printInfo();
        cout << "--- 学生信息 ---"  << endl;
        cout << "学号：" << getStudentId() << endl;
        cout << "专业：" << getMajor()     << endl;
        cout << "绩点：" << getGpa()       << endl;
        cout << "--- 教学信息 ---"  << endl;
        cout << "工号：" << getTeacherId()  << endl;
        cout << "院系：" << getDepartment() << endl;
        cout << "职称：" << getTitle()      << endl;
        cout << "负责课程：" << courseAssigned << endl;
    }
};


/* =========================================================
   main 函数
   ========================================================= */
int main() {

    // ---- 打印分隔线的辅助 lambda ----
    auto divider = [](const string& label) {
        cout << "\n========== " << label << " ==========" << endl;
    };

    // ---- 1. 实例化 3 个 Person 对象 ----
    divider("Person 对象");
    Person p1("张三", "1990-05-20");
    Person p2("李四", "1985-11-03");
    Person p3("王五", "2001-07-15");

    p1.printInfo(); cout << endl;
    p2.printInfo(); cout << endl;
    p3.printInfo();

    // ---- 2. 实例化学生 ----
    divider("Student 对象");
    Student s1("小明", "2002-03-10", "S20220001", "计算机科学", 3.8);
    Student s2("小红", "2003-08-22", "S20230042", "软件工程",   3.5);

    s1.printInfo(); cout << endl;
    s2.printInfo();

    // ---- 3. 实例化老师 ----
    divider("Teacher 对象");
    Teacher t1("陈教授", "1975-01-18", "T10086", "计算机学院", "教授");
    Teacher t2("林老师", "1988-06-30", "T10099", "软件学院",   "讲师");

    t1.printInfo(); cout << endl;
    t2.printInfo();

    // ---- 4. 实例化助教 ----
    divider("TeachingAssistant 对象");
    TeachingAssistant ta("赵七", "2000-09-01",
                         "S20190088", "计算机科学", 3.9,
                         "TA00012",   "计算机学院", "助教",
                         "数据结构");
    ta.printInfo();

    // ---- 5. 进阶：多态 —— 用 Person* 数组统一管理 ----
    divider("多态演示（Person* 指针数组）");

    // 注意：TeachingAssistant 继承自 StudentV/TeacherV（均虚继承自 Person）
    // 需要先转为 StudentV* 再隐式转为 Person*
    Person* people[] = { &p1, &s1, &s2, &t1, &t2,
                         static_cast<StudentV*>(&ta) };
    int count = sizeof(people) / sizeof(people[0]);

    for (int i = 0; i < count; i++) {
        cout << "--- 第 " << i + 1 << " 位 ---" << endl;
        people[i]->printInfo();   // 虚函数：自动调用各自重写的版本
        cout << endl;
    }

    return 0;
}