#pragma once

struct RGB
{
    int r;
    int g;
    int b;
};
bool operator==(const RGB& lhs, const RGB& rhs);