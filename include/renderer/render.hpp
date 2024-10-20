#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "object/ObjectManager.hpp"
#include "object/GameObject.hpp"
namespace neo::renderer
{
	class Render
	{
	public:
		Render() :_map(50, std::vector<char>(100,' '))
		{
			
		}

		void Draw(object::ObjectManager& manager)
		{
			for (auto& [name,obj] : manager.GetContainder())
			{
				_map[obj->GetTransform().GetPosition()._y][obj->GetTransform().GetPosition()._x] = obj->GetShape();
			}
			
			for (int y = 0; y < _map.size(); y++)
			{
				for (int x = 0; x < _map[0].size(); x++)
				{

					if (y == 0 || x == 0)
						std::cout << "#";
					else if (y + 1 == _map.size())
						std::cout << "#";
					else if (x + 1 == _map[0].size())
						std::cout << "#";
					else
						std::cout << _map[y][x];
				}
				std::cout << "\n";
			}
		}

		void Clear()
		{
			system("cls");
			for (int y = 0; y < _map.size(); y++)
			{
				for (int x = 0; x < _map[0].size(); x++)
				{
					_map[y][x] =' ';
				}
			}
		}

	private:
		std::vector<std::vector<char>> _map;
	};
}