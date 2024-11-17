#pragma once
#include <iostream>
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
		void Draw();
		void Clear();
		void Rendering();

    public:
        bool RenderingCheck(int x,int y);

	private:
		RenderBuffer* _frontBuffer;
		RenderBuffer* _backBuffer;

        uint32_t _height;
        uint32_t _width;
	};
}