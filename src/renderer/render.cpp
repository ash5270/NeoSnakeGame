#include "../../include/renderer/render.hpp"
#include <ranges>
neo::renderer::Render::Render(const uint32_t& height, const uint32_t& width) : _height(height),_width(width)
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
	for (const auto& obj : manager.GetContainder() | std::views::values)
	{
        auto& objTransform = obj->GetTransform();
        if(RenderingCheck(objTransform.GetPosition()._x,objTransform.GetPosition()._y))
        {
            _backBuffer->GetBuffer()[obj->GetTransform().GetPosition()._y][obj->GetTransform().GetPosition()._x] = obj->GetShape();
        }
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

bool neo::renderer::Render::RenderingCheck(int x, int y) {
    if( x>=0 && y>=0)
    {
        if(y<_height && x<_width)
        {
            return true;
        }
    }
    return false;
}
