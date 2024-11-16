#pragma once
#include "object/GameObject.hpp"
#include "system/InputSystem.hpp"
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
            const char input =neo::system::InputSystem::GetKey();
            if(input =='w'||input=='W')
            {
                _transform.GetPosition()._y -= 1;
            }
            else if(input == 's' || input=='S')
            {
                _transform.GetPosition()._y += 1;
            }
            else if(input == 'a' || input=='A')
            {
                _transform.GetPosition()._x -= 1;
            }
            else if(input == 'd' || input=='D')
            {
                _transform.GetPosition()._x += 1;
            }
		    std::cout<<"x,y"<<this->_transform.GetPosition()._x<<","<<this->_transform.GetPosition()._y<<"\n";
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