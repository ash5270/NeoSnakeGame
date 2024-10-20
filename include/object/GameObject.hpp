#pragma once
#include "object/IObject.hpp"
#include "object/Transform.hpp"
#include <unordered_map>
#include <memory>

namespace neo::object
{
	class GameObject : public IObject
	{
	public:
		using ConponentPtr = std::shared_ptr<IConponent>;
	public:
		GameObject(const std::string& name, const char& shape);
	public:
		Transform& GetTransform() { return _transform; }
		ConponentPtr& GetConpoent(const std::string& name) { return _conponetManager[name]; }
		char GetShape() { return _shape; }
	protected:
		std::unordered_map<std::string, ConponentPtr> _conponetManager;
		Transform _transform;
		std::string _name;
		char _shape;
	}; 
}