#include <iostream>

#include "blue.h"
#include "midnightblue.h"
#include "orange.h"

template <typename T>
T max(const T first, const T second)
{
    return first > second ? first : second;
}

int main()
{
    // std::cout << max<int>(1, 2) << std::endl;
    // std::cout << max<float>(10.7, 2.0) << std::endl;
    // std::cout << max<char>('c', 'z') << std::endl;

    Blue blue;
    MidNightBlue midNightBlue;
    Orange orange;

    std::cout << blue.toString() << ' ' << blue.toChinese() << std::endl;
    std::cout << midNightBlue.toString() << ' ' << midNightBlue.toChinese() << std::endl;
    std::cout << orange.toString() << ' ' << orange.toChinese() << std::endl;

    return 0;
}