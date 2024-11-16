#include "../../include/system/timer.hpp"

time_t neo::system::Timer::_deltaTime =0;
time_t neo::system::Timer::_nextTime =0;
time_t neo::system::Timer::_prevTime =0;

void neo::system::Timer::Init() {
    _nextTime = std::chrono::system_clock::now().time_since_epoch().count();
    _prevTime = std::chrono::system_clock::now().time_since_epoch().count();
}

void neo::system::Timer::Update() {
    _prevTime = _nextTime;
    _nextTime = std::chrono::system_clock::now().time_since_epoch().count();
    _deltaTime = _nextTime - _prevTime;
}

time_t neo::system::Timer::GetDeltaTime() {
    return _deltaTime;
}