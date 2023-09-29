#pragma once

#include "icolor_generator.h"
#include "rgb.h"

class GradientGenerator : public IColorGenerator
{
public:
    GradientGenerator();
    RGB get() override;
    bool is_end() const override;

private:
    void to_next_state();

private:
    RGB cur_rgb;
};
