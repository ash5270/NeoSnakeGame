#include "../../include/system/InputSystem.hpp"
#include <unistd.h>

std::atomic_bool neo::system::InputSystem::_isUpdate = false;
std::atomic<char> neo::system::InputSystem::_lastInput = 0;
std::thread neo::system::InputSystem::_thread = {};
struct termios neo::system::InputSystem::_oldT = {};
struct termios neo::system::InputSystem::_newT = {};
int neo::system::InputSystem::_peekChar = -1;

void neo::system::InputSystem::Update() {
    if (_kbhit()) {
        char input = _getchar();
        _putch(input);
        _lastInput=input;
    }
    std::cout << "last : " << _lastInput << " ";
}

void neo::system::InputSystem::Init() {
    _isUpdate.store(true);
    tcgetattr(0, &_oldT);
    _newT = _oldT;
    _newT.c_lflag &= ~ICANON;
    _newT.c_lflag &= ~ECHO;
    _newT.c_cc[VMIN] = 1;
    _newT.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &_newT);
    //enableNonBlockingInput();
    //_thread = std::thread(&neo::system::InputSystem::InputUpdate);
}

void neo::system::InputSystem::Release() {
    _isUpdate.store(false);
    tcsetattr(0, TCSANOW, &_newT);
    if (_thread.joinable() == true)
        _thread.join();
}

void neo::system::InputSystem::InputUpdate() {
    while (_isUpdate) {
        char inputKey = getchar();
        _lastInput.store(inputKey);
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

char neo::system::InputSystem::GetInput() {
    return 0;
}


char neo::system::InputSystem::GetKey() {
    return _lastInput;
}

void neo::system::InputSystem::enableNonBlockingInput() {
    struct termios new_termios;

    new_termios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
}

void neo::system::InputSystem::disableNonBlockingInput() {

}

char neo::system::InputSystem::_kbhit() {
    unsigned char ch;
    int nread;
    if (_peekChar != -1)
        return 1;
    _newT.c_cc[VMIN] = 0;
    tcsetattr(0, TCSANOW, &_newT);
    nread = read(0, &ch, 1);
    _newT.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &_newT);
    if (nread == 1) {
        _peekChar = ch;
        return 1;
    }
    return 0;
}

int neo::system::InputSystem::_getchar() {
    char ch;
    if (_peekChar != -1) {
        ch = _peekChar;
        _peekChar = -1;
        return ch;
    }
    read(0, &ch, 1);
    return ch;
}

int neo::system::InputSystem::_putch(int c) {
    putchar(c);
    fflush(stdout);
    return c;
}

void neo::system::InputSystem::FlushKey() {
    _lastInput =0;
}



