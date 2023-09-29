#include "rgb.h"

bool operator==(const RGB &lhs, const RGB &rhs)
{
    return lhs.r == rhs.r && lhs.g == rhs.g && lhs.b == rhs.b;
}