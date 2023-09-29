#pragma once
#include "rgb.h"

class IColorGenerator
{
public:
    virtual ~IColorGenerator() = default;

    virtual RGB get() = 0;
    virtual bool is_end() const = 0;
};