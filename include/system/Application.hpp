#pragma once
#include "object/ObjectManager.hpp"
#include "renderer/render.hpp"
#include "InputSystem.hpp"

namespace neo::system
{
	class Application
	{
	public:
		Application();
		~Application();
	public:
		bool Init();
		void Start();
		void Update();
		void Stop();
		void Release();
	private:
		object::ObjectManager _objectManager;
		renderer::Render _render;
	};
}


