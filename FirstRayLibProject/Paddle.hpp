#pragma once
#include <raylib.h>

class Paddle
{
protected:
	float _x_position;
	float _y_position;
	float _width;
	float _height;
	int _speed;
	int _score;

	void LimitMovement();
public:
	Paddle(float x_pos, float y_pos, float width, float height,int speed)
		: _x_position(x_pos), _y_position(y_pos), _width(width), _height(height), _speed(speed),_score(0){}

	Paddle() : _x_position(0), _y_position(0), _width(0), _height(0), _speed(0), _score(0) {}

	void Draw();
	void Update(int = 0);

	//Getter
	float GetXPosition() const;
	float GetYPosition() const;
	float GetWidth() const;
	float GetHeight() const;
	int GetSpeed() const;
	int GetScore() const;

	//Setter
	void SetXPosition(float x_pos);
	void SetYPosition(float y_pos);
	void SetWidth(float width);
	void SetHeight(float height);
	void SetSpeed(int speed);
	void SetScore(int score);
};

