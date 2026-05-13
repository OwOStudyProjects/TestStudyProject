#include <format>
#include "color.h"

Color::Color() : r(0), g(0), b(0), a(0)
{
}

Color::Color(int r, int g, int b, int a) : r(r), g(g), b(b), a(a)
{
}

std::string Color::toString() const
{
    return std::format("rgba({}, {}, {}, {})", r, g, b, a);
}

Color &Color::setA(const int a)
{
    this->a = a;
    return *this;
}

Color &Color::setR(const int r)
{
    this->r = r;
    return *this;
}

Color &Color::setG(const int g)
{
    this->g = g;
    return *this;
}

Color &Color::setB(const int b)
{
    this->b = b;
    return *this;
}

int Color::getA() const
{
    return this->a;
}

int Color::getR() const
{
    return this->r;
}

int Color::getG() const
{
    return this->g;
}

int Color::getB() const
{
    return this->b;
}