#pragma once
#include <raylib.h>
#include "Paddle.hpp"
#include "CpuPaddle.h"
#include <iostream> 

class Ball
{
private:
	float _x_position;
	float _y_position;
	int _x_speed;
	int _y_speed;
	int _radius;
	CpuPaddle& _cpu;
	Paddle& _player;
public:
	Ball(float x_pos, float y_pos, int x_speed, int y_speed, int radius, CpuPaddle& cpu, Paddle& player)
		: _x_position(x_pos), _y_position(y_pos), _x_speed(x_speed), _y_speed(y_speed), _radius(radius),_cpu(cpu),_player(player) {}
	

	void Draw();
	void Update();
	void ResetBall();

	//Getter
	float GetXPosition() const;
	float GetYPosition() const;
	int GetXSpeed() const;
	int GetYSpeed() const;
	int GetRadius() const;

	//Setter

	void SetXPosition(float x_pos);
	void SetYPosition(float y_pos);
	void SetXSpeed(int x_speed);
	void SetYSpeed(int y_speed);
	void SetRadius(int radius);
};

