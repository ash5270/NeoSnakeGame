#pragma once
#include "object/IComponent.hpp"
#include "math/Vector2.hpp"
namespace neo::object
{
	class Transform : public IConponent
	{
	public:
		using vec2 = math::Vector2;
	public:
		Transform();
		~Transform();
		vec2& GetPosition();
	private:
		vec2 _vec2;
	};
}