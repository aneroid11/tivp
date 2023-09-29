#include "gradient_generator.h"

GradientGenerator::GradientGenerator() :
        cur_rgb{256, 256, 256}
{}

RGB GradientGenerator::get()
{
    to_next_state();
    return cur_rgb;
}

void GradientGenerator::to_next_state()
{
    cur_rgb.r -= 1;
    cur_rgb.g -= 1;
    cur_rgb.b -= 1;
}

bool GradientGenerator::is_end() const
{
    return cur_rgb == RGB{0, 0, 0};
}
