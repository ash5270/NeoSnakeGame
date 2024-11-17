#pragma once
#include "object/GameObject.hpp"
#include "system/InputSystem.hpp"
#include<iostream>

namespace neo::game
{
	class SnakeObject : public neo::object::GameObject
	{
    public:
        using BodyPtr = std::shared_ptr<class SnakeBodyObject>;
	public:
		SnakeObject();
		~SnakeObject() override;
	public:
		void Init() override { std::cout << "Init" << std::endl; };
		void Start() override { std::cout << "Start" << std::endl;	 };
		void Update() override;
		void LastUpdate() override;
	private:
        void _BodyUpdate();
    private:
        bool _isEnd;
        std::vector<BodyPtr> _bodys;
        math::Vector2 _lastPosition;
        math::Vector2 _lastBodyPosition;
	};


}