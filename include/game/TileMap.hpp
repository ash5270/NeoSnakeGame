#pragma once
#include "object/GameObject.hpp"
#include "system/InputSystem.hpp"
#include "TileObject.hpp"
#include <vector>

namespace neo::game {
    class TileMap : public neo::object::GameObject {
    public:
        using TileObject_Ptr = std::unique_ptr<TileObject>;
    public:
        TileMap();
        ~TileMap() override;
    public:
        void Init() override;
        void Start() override;
        void Update() override;
        void LastUpdate() override;

    private:
        std::vector<TileObject_Ptr> _tileObjects;

    };
}