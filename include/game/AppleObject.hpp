#pragma once

#include "object/GameObject.hpp"
#include "object/ObjectManager.hpp"
#include "system/InputSystem.hpp"

#include<iostream>

namespace neo::game {
    class AppleObject : public neo::object::GameObject {
    public:
        AppleObject(): neo::object::GameObject("Apple",'*'){
            _transform.GetPosition()= math::Vector2(5,5);
        }
        ~AppleObject() override{}
    public:
        void Init() override { std::cout << "Init" << std::endl; };
        void Start() override { std::cout << "Start" << std::endl;	 };
        void Update() override {
            auto& objects = GetObjectManager().GetContainder();
            const auto& playerPos= objects["player"]->GetTransform().GetPosition();
            if(playerPos._x==_transform.GetPosition()._x&&playerPos._y ==_transform.GetPosition()._y)
            {

            }
        }
        void LastUpdate() override {};
    };
}