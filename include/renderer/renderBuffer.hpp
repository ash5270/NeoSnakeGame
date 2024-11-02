#pragma once
#include<vector>

namespace neo::renderer
{
	class RenderBuffer
	{
	public:
		using buf = std::vector<std::vector<char>>;
	public:
		RenderBuffer(const uint32_t& height, const uint32_t& width);
		~RenderBuffer();
	public:
		void clear();
		buf& GetBuffer();
	private:
		buf _buffer;
	};
}