#pragma once

struct scene
{
    scene() = default;
    virtual ~scene() = default;
    virtual void update() = 0;
};
