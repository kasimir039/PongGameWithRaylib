#include "Paddle.hpp"

void Paddle::Draw()
{
	DrawRectangle(this->_x_position, this->_y_position ,this->_width,this->_height,WHITE);

}
void Paddle::Update(int)
{
	if (IsKeyDown(KEY_UP))
		this->_y_position -= this->_speed;

	if (IsKeyDown(KEY_DOWN))
		this->_y_position += this->_speed;

	LimitMovement();
}

void Paddle::LimitMovement()
{
	if (this->_y_position <= 0)
		this->_y_position = 0;

	if (this->_y_position + this->_height >= GetScreenHeight())
		this->_y_position = GetScreenHeight() - this->_height;
}


float Paddle::GetXPosition() const{ return this->_x_position; }
float Paddle::GetYPosition() const{ return this->_y_position; }
float Paddle::GetWidth() const{ return this->_width; }
float Paddle::GetHeight() const{ return this->_height; }
int Paddle::GetSpeed() const{ return this->_speed; }
int Paddle::GetScore() const{ return this->_score; }
void Paddle::SetXPosition(float x_pos){ this->_x_position = x_pos; }
void Paddle::SetYPosition(float y_pos){ this->_y_position = y_pos; }
void Paddle::SetWidth(float width){ this->_width = width; }
void Paddle::SetHeight(float height){ this->_height = height; }
void Paddle::SetSpeed(int speed){ this->_speed = speed; }

void Paddle::SetScore(int score){ this->_score = score; }
