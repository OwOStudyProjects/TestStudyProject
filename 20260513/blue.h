#ifndef BLUE_H
#define BLUE_H

#include "color.h"

class Blue : public Color
{
public:
    Blue() : Color(0, 0, 255, 1) {}

    std::string toString() const override;
    std::string toChinese() const override;
};

#endif