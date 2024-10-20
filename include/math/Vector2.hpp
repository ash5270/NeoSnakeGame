#pragma once

namespace neo::math
{
	struct Vector2
	{
		Vector2():_y(0.f),_x(0.f){}
		Vector2(const float& x,const float& y):_x(x),_y(y){}
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

		float _x = 0.f;
		float _y = 0.f;
	};
}
