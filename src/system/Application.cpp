#include "../../include/system/Application.hpp"
#include "../../include/object/IObject.hpp"
#include "../../include/game/SnakeObject.hpp"
#include "../../include/game/TileMap.hpp"
#include "../../include/game/AppleObject.hpp"

#include<thread>
neo::system::Application::Application(): _render(15,40)
{

}

neo::system::Application::~Application()
{

}

bool neo::system::Application::Init()
{
    GetObjectManager().RegisterObject("player", std::make_shared<neo::game::SnakeObject>());
    GetObjectManager().RegisterObject("TileMap",std::make_shared<neo::game::TileMap>());
    GetObjectManager().RegisterObject("apple_1",std::make_shared<neo::game::AppleObject>());
	const auto& container = GetObjectManager().GetContainder();
	for (const auto& [name, object] : container)
	{
		object.get()->Init();
	}
    InputSystem::Init();
	return false;
}

void neo::system::Application::Start()
{
	const auto& container = GetObjectManager().GetContainder();
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
		const auto& container = GetObjectManager().GetContainder();
		for (const auto& [name, object] : container)
		{
			object.get()->Update();
		}
		_render.Clear();
		_render.Draw();
		_render.SwapBuffer();
		_render.Rendering();

        for (const auto& [name, object] : container)
        {
            object.get()->LastUpdate();
        }

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

