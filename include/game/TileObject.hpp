#pragma once
#include "object/GameObject.hpp"
#include "system/InputSystem.hpp"
#include<iostream>

namespace neo::game {
    class TileObject : public neo::object::GameObject {
    public:
        TileObject(const int& x,const int& y);
        ~TileObject() override =default;
    public:
        void Init() override;
        void Start() override;
        void Update() override;
        void LastUpdate() override;
    };
}