#include "../../include/object/Transform.hpp"

neo::object::Transform::Transform() : _vec2()
{

}

neo::object::Transform::~Transform()
{

}

neo::math::Vector2& neo::object::Transform::GetPosition() 
{
	return _vec2;
}
