#include "../../include/game/SnakeBodyObject.hpp"

neo::game::SnakeBodyObject::SnakeBodyObject(const int& x, const int& y): neo::object::GameObject("Body",'X') {
    _transform.GetPosition() = math::Vector2(x,y);
}

neo::game::SnakeBodyObject::~SnakeBodyObject() {

}
