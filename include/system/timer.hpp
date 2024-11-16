#pragma once
#include <chrono>
namespace neo::system
{
    class Timer
    {
    public:
        static void Init();
        static void Update();
        static time_t GetDeltaTime();
    private:
        static time_t _prevTime;
        static time_t _nextTime;
        static time_t _deltaTime;
    };
}