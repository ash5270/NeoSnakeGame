#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "object/ObjectManager.hpp"
#include "object/GameObject.hpp"
#include "renderer/renderBuffer.hpp"

namespace neo::renderer
{
	class Render
	{
	public:
		Render(const uint32_t& height, const uint32_t& width);
		~Render() = default;

	public:
		void SwapBuffer();
		void Draw(object::ObjectManager& manager);
		void Clear();
		void Rendering();

	private:
		RenderBuffer* _frontBuffer;
		RenderBuffer* _backBuffer;
	};
}