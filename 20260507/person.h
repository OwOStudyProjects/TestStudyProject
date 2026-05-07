#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>

class Person
{
private:
    std::string name;
    std::vector<int> birthday;
    int gender;
    long long int id;

protected:
    int age;

public:
    std::string motto;

    Person();
    ~Person();

    Person(const std::string &pName, const std::vector<int> &pBirthday, const int &pGender);

    // Getter: 通过一个指定的方法可以获取到指定的成员属性/变量

    // 返回人名
    std::string getName() const;

    // 返回生日
    std::string getBirthday() const;

    // 返回性别
    std::string getGender() const;

    // 返回ID
    long long int getId() const;

    int getAge() const;

    std::string getMotto() const;

    // Setter: 通过一个指定的方法可以设置成员内部属性/变量

    // 修改人名
    Person &setName(const std::string pName);

    // 修改生日
    Person &setBirthday(const std::vector<int> pBirthday);

    // 修改性别
    Person &setGender(const int pGender);

    // 修改ID
    Person &setId(const long long int pId);

    Person &setAge(const int pAge);

    Person &setMotto(const std::string pMotto);
};

#endif