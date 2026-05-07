#include <iostream>
#include "bruch.h"

int main()
{
    Bruch bruch_1_2 = Bruch(1, -2);
    Bruch bruch_4_5 = Bruch(4, 5);


    std::cout << bruch_1_2.toString() << std::endl;
    std::cout << bruch_4_5.toString() << std::endl;

    bruch_1_2.add(bruch_4_5);
    std::cout << bruch_1_2.toString() << std::endl;

    bruch_1_2.sub(bruch_4_5);
    std::cout << bruch_1_2.toString() << std::endl;

    bruch_1_2.mult(bruch_4_5);
    std::cout << bruch_1_2.toString() << std::endl;

    bruch_1_2.div(bruch_4_5);
    std::cout << bruch_1_2.toString() << std::endl;
    return 0;
}