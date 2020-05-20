#pragma once

#include "Object_name.h"

struct Game_object_meta
{
    Object_name name{Object_name::NONE};

    // You can do physics and graphics calculations on 'active' object only
    // If game object is not active - it's removed from game objects vector
    bool is_active{true};
};
