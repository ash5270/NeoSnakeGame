#include "../../include/game/TileObject.hpp"

neo::game::TileObject::TileObject(const int &x, const int &y) : neo::object::GameObject("Tile",'@') {
    _transform.GetPosition()._x = x;
    _transform.GetPosition()._y =y;
}

void neo::game::TileObject::Init() {

}

void neo::game::TileObject::Start() {

}

void neo::game::TileObject::Update() {

}

void neo::game::TileObject::LastUpdate() {

}
