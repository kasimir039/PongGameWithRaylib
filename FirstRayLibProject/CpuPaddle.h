#pragma once
#include "Paddle.hpp"


class CpuPaddle : public Paddle
{
public:

    CpuPaddle(float x_pos, float y_pos, float width, float height, int speed)
        : Paddle(x_pos, y_pos, width, height, speed){}


    void Update(int pos);

};

