#pragma once
#include "object/ObjectManager.hpp"
#include "renderer/render.hpp"
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
		void Input();

	private:
		object::ObjectManager _objectManager;
		renderer::Render _render;
		
	};
}


