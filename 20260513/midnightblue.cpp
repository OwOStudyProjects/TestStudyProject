#include "midnightblue.h"

// 注意: 由于此类继承了 Blue 类, 因此在直接使用 toString() 方法时, 会直接输出 Blue 类的覆盖写法!

std::string MidNightBlue::toChinese() const
{
    return "海军蓝";
}

