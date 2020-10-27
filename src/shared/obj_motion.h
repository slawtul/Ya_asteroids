#pragma once

struct obj_motion
{
    double max_speed;
    double angle;
    double dx;
    double dy;
    double acceleration{ 0.2 };
};
