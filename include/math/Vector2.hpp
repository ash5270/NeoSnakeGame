#pragma once
#include <inttypes.h>
namespace neo::math
{
	struct Vector2
	{
		Vector2():_y(0),_x(0){}
		Vector2(const int32_t& x,const int32_t& y):_x(x),_y(y){}
		Vector2(const Vector2& vec2)
		{
			this->_x = vec2._x;
			this->_y = vec2._y;
		}

		Vector2 operator+(const Vector2 vec2)
		{
			return Vector2(this->_x + vec2._x, this->_y + vec2._y );
		}

		Vector2 operator-(const Vector2 vec2)
		{
			return Vector2( this->_x - vec2._x, this->_y - vec2._y );
		}

		int32_t _x = 0;
        int32_t _y = 0;
	};
}
