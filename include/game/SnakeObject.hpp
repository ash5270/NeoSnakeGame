#pragma once
#include "object/GameObject.hpp"
#include<iostream>
namespace neo::game
{
	class SnakeObject : public neo::object::GameObject
	{
	public:
		SnakeObject();
		~SnakeObject();
	public:
		void Init() override { std::cout << "Init" << std::endl; };
		void Start() override { std::cout << "Start" << std::endl;	 };
		void Update() override { 
			
			_transform.GetPosition()._x += 1;
			_transform.GetPosition()._y += 1;
		
		};
		void LastUpdate() override { std::cout << "Last Update" << std::endl; };
	private:

	};

	SnakeObject::SnakeObject():neo::object::GameObject("player",'#')
	{

	}

	SnakeObject::~SnakeObject()
	{

	}
}