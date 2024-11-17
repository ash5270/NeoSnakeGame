#include "../../include/game/SnakeObject.hpp"
#include "../../include/game/SnakeBodyObject.hpp"
#include "../../include/object/ObjectManager.hpp"

neo::game::SnakeObject::SnakeObject() : neo::object::GameObject("player", '#'), _lastPosition(), _isEnd(true),
                                        _lastBodyPosition() {
    _transform.GetPosition() = math::Vector2(4, 1);
    _lastPosition = _transform.GetPosition();
    for (int i = 0; i < 3; i++) {
        _bodys.push_back(std::make_shared<neo::game::SnakeBodyObject>(1 + i, 1));
        GetObjectManager().RegisterObject(std::format("body_{}", i), _bodys.back());
    }

    _lastBodyPosition = _bodys.back()->GetTransform().GetPosition();
}

neo::game::SnakeObject::~SnakeObject() {

}

void neo::game::SnakeObject::Update() {
    if (_isEnd == false)
        return;
    if (_lastPosition._x != _transform.GetPosition()._x || _lastPosition._y != _transform.GetPosition()._y) {
        _BodyUpdate();
    }
    const char input = neo::system::InputSystem::GetKey();
    if (input == 'w' || input == 'W') {
        _transform.GetPosition()._y -= 1;
    } else if (input == 's' || input == 'S') {
        _transform.GetPosition()._y += 1;
    } else if (input == 'a' || input == 'A') {
        _transform.GetPosition()._x -= 1;
    } else if (input == 'd' || input == 'D') {
        _transform.GetPosition()._x += 1;
    }
    std::cout << "x,y" << this->_transform.GetPosition()._x << "," << this->_transform.GetPosition()._y << "\n";
}

void neo::game::SnakeObject::_BodyUpdate() {
    if (_bodys.size() >= 1) {
        _lastBodyPosition = _bodys.back()->GetTransform().GetPosition();
        for (auto end = _bodys.size() - 1; end >= 1; end--) {
            _bodys[end]->GetTransform().GetPosition() = _bodys[end - 1]->GetTransform().GetPosition();
        }
        _bodys.front()->GetTransform().GetPosition() = _transform.GetPosition();
    }
}

void neo::game::SnakeObject::LastUpdate() {
    const auto &objects = GetObjectManager().GetContainder();
    for (const auto &[name, object]: objects) {
        if (object->GetTransform().GetPosition()._x == _transform.GetPosition()._x &&
            object->GetTransform().GetPosition()._y == _transform.GetPosition()._y) {
            if (object->GetShape() == '@') {
                std::cout << "end" << "\n";
                neo::system::InputSystem::FlushKey();
                _isEnd = false;
            } else if (object->GetShape() == 'X') {
                std::cout << "end" << "\n";
                neo::system::InputSystem::FlushKey();
                _isEnd = false;
            } else if (object->GetShape() == '*') {
                const auto &lastBodyPos = _lastBodyPosition;
                _bodys.push_back(std::make_shared<neo::game::SnakeBodyObject>(lastBodyPos._x, lastBodyPos._y));
                GetObjectManager().RegisterObject(std::format("body_{}", _bodys.size()), _bodys.back());
            }
        }
    }
}
