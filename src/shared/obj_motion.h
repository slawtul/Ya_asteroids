#ifndef OBJ_MOTION_H
#define OBJ_MOTION_H


struct obj_motion
{
    double max_speed;
    double angle;
    double dx;
    double dy;
    double acceleration{ 0.2 };
};


#endif // OBJ_MOTION_H
