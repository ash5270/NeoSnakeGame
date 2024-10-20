#include "../../include/object/ObjectManager.hpp"
#include "../../include/object/IObject.hpp"

neo::object::ObjectManager::ObjectManager()
{
}

neo::object::ObjectManager::~ObjectManager()
{

}

void neo::object::ObjectManager::RegisterObject(const std::string_view name, const ObjectPtr& object)
{
	if (_container.contains(name.data()) == false)
	{
		_container.insert({ name.data(),object});
	}
}

void neo::object::ObjectManager::UnreigsterObject(const std::string_view name)
{
	if (_container.contains(name.data()) == true)
	{
		_container.erase(name.data());
	}
}
