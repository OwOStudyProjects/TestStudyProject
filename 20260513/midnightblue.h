#ifndef MIDNIGHTBLUE_H
#define MIDNIGHTBLUE_H

#include "blue.h"

class MidNightBlue : public Blue
{
public:
    MidNightBlue()
    {
        this->a = 1;
        this->r = 25;
        this->g = 25;
        this->b = 112;
    }

    std::string toChinese() const override;
};

#endif