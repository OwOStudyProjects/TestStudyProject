#include <iostream>
#include "person.h"


// 构造函数 方法一
Person::Person()
{
    // 与设定的三个默认值, 防止获取值为空

    name = "OwOBlog";
    birthday = {20216, 7, 18};
    gender = 1;
}

Person::~Person()
{
    std::cout << "对象 Person 的内存空间已被释放" << std::endl;
}

// 构造函数 方法二
/* Person::Person(const std::string &pName, const std::vector<int> &pBirthday, const int &pGender)
{
    name = pName;
    birthday = pBirthday;
    gender = pGender;
} */

// 构造函数 方法三
// 使用初始化列表来初始化字段
Person::Person(const std::string &pName,
               const std::vector<int> &pBirthday,
               const int &pGender) : name(pName), birthday(pBirthday), gender(pGender)
{
}

std::string Person::getName() const
{
    return name;
}

std::string Person::getBirthday() const
{
    if (birthday.size() < 3)
    {
        return "undefined birthday:vector<int>";
    }

    /* // GPT 推荐写法
    std::ostringstream oss;
    oss << std::setfill('0')
        << std::setw(4) << birthday[0] << "-"
        << std::setw(2) << birthday[1] << "-"
        << std::setw(2) << birthday[2];

    return oss.str(); */

    char buffer[15];
    sprintf(buffer, "%.4d-%.2d-%.2d", birthday[0], birthday[1], birthday[2]);

    return buffer;
}

std::string Person::getGender() const
{
    return (gender == 0) ? "Female" : "Male";
}

long long int Person::getId() const
{
    return id;
}

int Person::getAge() const
{
    return age;
}

std::string Person::getMotto() const
{
    return motto;
}

Person &Person::setName(const std::string name)
{
    this->name = name;
    return *this;
}

Person &Person::setBirthday(const std::vector<int> pBirthday)
{
    birthday = pBirthday;
    return *this;
}

Person &Person::setGender(const int pGender)
{
    gender = pGender;
    return *this;
}

Person &Person::setId(const long long int pId)
{
    id = pId;
    return *this;
}

Person &Person::setAge(const int pAge)
{
    age = pAge;
    return *this;
}

Person &Person::setMotto(const std::string pMotto)
{
    motto = pMotto;
    return *this;
}