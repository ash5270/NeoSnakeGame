#include "../../include/system/Application.hpp"
#include "../../include/object/IObject.hpp"
#include "../../include/game/SnakeObject.hpp"

#include<thread>
neo::system::Application::Application(): _render(10,10)
{

}

neo::system::Application::~Application()
{

}

bool neo::system::Application::Init()
{
	_objectManager.RegisterObject("player", std::make_shared<neo::game::SnakeObject>());
	const auto& container = _objectManager.GetContainder();
	for (const auto& [name, object] : container)
	{
		object.get()->Init();
	}
    InputSystem::Init();
	return false;
}

void neo::system::Application::Start()
{
	const auto& container = _objectManager.GetContainder();
	for (const auto& [name, object] : container)
	{
		object.get()->Start();
	}
}

void neo::system::Application::Update()
{
	while (true)
	{
        InputSystem::Update();



		const auto& container = _objectManager.GetContainder();
		for (const auto& [name, object] : container)
		{
			object.get()->Update();
		}
		_render.Clear();
		_render.Draw(_objectManager);
		_render.SwapBuffer();
		_render.Rendering();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

void neo::system::Application::Stop()
{

}

void neo::system::Application::Release()
{
    InputSystem::Release();
}

