#include "CpuPaddle.h"

void  CpuPaddle::Update(int pos) 
{
	if (this->_y_position + this->_height / 2 >= pos)
		this->_y_position -= this->_speed;
	
	if (this->_y_position + this->_height / 2 <= pos)
		this->_y_position += this->_speed;


	LimitMovement();

}
