#ifndef ORANGE_H
#define ORANGE_H

#include "color.h"

class Orange : public Color
{
public:
    Orange() : Color(255, 165, 0, 1) {}

    std::string toChinese() const override;
};

#endif