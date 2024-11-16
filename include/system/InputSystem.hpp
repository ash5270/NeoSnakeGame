#pragma once
#include <future>
#include <thread>
#include <chrono>
#include <iostream>
#include <termios.h>
#include <fcntl.h>
namespace neo::system
{
    class InputSystem
    {
    public:
        InputSystem() =delete;
        ~InputSystem() = delete;
    public:
        static void Init();
        static void Release();
        static void Update();
        static char GetKey();
    private:
        static void InputUpdate();
        static char GetInput();
        static char _kbhit();
        static int _getchar();
        static int _putch(int c);
        static void enableNonBlockingInput();
        static void disableNonBlockingInput();
    private:
        static struct termios _oldT,_newT;
        static std::atomic_bool _isUpdate ;
        static std::thread _thread;
        static std::atomic<char>_lastInput;

        static int _peekChar ;
    };
}