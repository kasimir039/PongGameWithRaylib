#include "Ball.hpp"

void Ball::Draw()
{
	DrawCircle(this->_x_position, this->_y_position, this->_radius, WHITE);
}

void Ball::Update()
{

    this->_x_position += this->_x_speed;
    this->_y_position += this->_y_speed;

    if (this->_y_position + this->_radius > GetScreenHeight() || this->_y_position - this->_radius <= 0)
    {
        this->_y_speed *= -1;
    }

    if (this->_x_position + this->_radius >= GetScreenWidth())
    {
        _cpu.SetScore(_cpu.GetScore() + 1);
        ResetBall();
    }

    if (this->_x_position - this->_radius <= 0)
    {
        _player.SetScore(_player.GetScore() + 1);
        ResetBall();
    }

}

void Ball::ResetBall()
{
	this->_x_position = GetScreenWidth() / 2;
	this->_y_position = GetScreenHeight() / 2;

	int speedChoice[2] = { 1,-1 };
	this->_x_speed *= speedChoice[GetRandomValue(0, 1)];
	this->_y_speed *= speedChoice[GetRandomValue(0, 1)];

}

float Ball::GetXPosition() const { return this->_x_position; }
float Ball::GetYPosition() const { return this->_y_position; }
int Ball::GetXSpeed() const { return this->_x_speed; }
int Ball::GetYSpeed() const { return this->_y_speed;}
int Ball::GetRadius() const { return this->_radius; }

void Ball::SetXPosition(float x_pos) { this->_x_position = x_pos; }
void Ball::SetYPosition(float y_pos) { this->_y_position = y_pos; }
void Ball::SetXSpeed(int x_speed) { this->_x_speed = x_speed; }
void Ball::SetYSpeed(int y_speed) { this->_y_speed = y_speed; }
void Ball::SetRadius(int radius) { this->_radius = radius; }