#ifndef COLOR_H
#define COLOR_H

#include <string>

class Color
{
protected:
    int r; // red
    int g; // green
    int b; // blue
    int a; // alpha: transparency

public:
    Color();
    Color(int r, int g, int b, int a);

    // 以字符串方式返回颜色编码 (虚函数)
    virtual std::string toString() const;

    Color &setA(const int a);
    Color &setR(const int r);
    Color &setG(const int g);
    Color &setB(const int b);

    int getA() const;
    int getR() const;
    int getG() const;
    int getB() const;

    virtual std::string toChinese() const = 0;
};

#endif