#pragma once
#include "object/GameObject.hpp"
#include "system/InputSystem.hpp"
#include<iostream>

namespace neo::game
{
    class SnakeBodyObject : public neo::object::GameObject
    {
    public:
        SnakeBodyObject(const int& x, const int& y);
        ~SnakeBodyObject() override;
    public:
        void Init() override { std::cout << "Init" << std::endl; };
        void Start() override { std::cout << "Start" << std::endl;	 };
        void Update() override {}
        void LastUpdate() override {  };
    };
}