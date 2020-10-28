#ifndef OBJ_META_H
#define OBJ_META_H


#include "obj_name.h"


struct obj_meta
{
    obj_name name{ obj_name::NONE };

    // You can do physics and gfx calculations on 'active' object only
    // If game object is not active - it's removed from game objects vector
    bool is_active{ true };
};


#endif // OBJ_META_H
