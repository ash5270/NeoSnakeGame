#pragma once
#include<string>
namespace neo::object
{
	class IObject
	{
	public:
		virtual void Init() = 0;
		virtual void Start() = 0;
		virtual void Update() = 0;
		virtual void LastUpdate() = 0;
	};
}