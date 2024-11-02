#include "../../include/renderer/render.hpp"

neo::renderer::Render::Render(const uint32_t& height, const uint32_t& width) 
{
	_frontBuffer = new RenderBuffer(height, width);
	_backBuffer = new RenderBuffer(height, width);
}

void neo::renderer::Render::SwapBuffer()
{
	auto temp = _frontBuffer;
	_frontBuffer = _backBuffer;
	_backBuffer = temp;
}


void neo::renderer::Render::Draw(object::ObjectManager& manager)
{
	//back buffer insert
	_backBuffer->clear();
	for (auto& [name, obj] : manager.GetContainder())
	{
		_backBuffer->GetBuffer()[obj->GetTransform().GetPosition()._y][obj->GetTransform().GetPosition()._x] = obj->GetShape();
	}
}

void neo::renderer::Render::Clear()
{
	//system("cls");
	std::cout << "\033[H";
}

void neo::renderer::Render::Rendering()
{
	for (int y = 0; y < _frontBuffer->GetBuffer().size(); y++)
	{
		for (int x = 0; x < _frontBuffer->GetBuffer()[0].size(); x++)
		{
			if (y == 0 || x == 0)
				std::cout << "#";
			else if (y + 1 == _frontBuffer->GetBuffer().size())
				std::cout << "#";
			else if (x + 1 == _frontBuffer->GetBuffer()[0].size())
				std::cout << "#";
			else
				std::cout << _frontBuffer->GetBuffer()[y][x];
		}
		std::cout << "\n";
	}
}
