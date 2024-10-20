#pragma once
#include<unordered_map>
#include<memory>
#include<string>
namespace neo::object
{
	class ObjectManager
	{
	public:
		using ObjectPtr = std::shared_ptr <class GameObject>;
	public:
		ObjectManager();
		~ObjectManager();
	public:
		void RegisterObject(const std::string_view name,const ObjectPtr& object);
		void UnreigsterObject(const std::string_view name);

		std::unordered_map<std::string, ObjectPtr>& GetContainder() { return _container; }
	private:
		std::unordered_map<std::string, ObjectPtr> _container;
	};
}