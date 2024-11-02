#include "../../include/renderer/renderBuffer.hpp"

neo::renderer::RenderBuffer::RenderBuffer(const uint32_t& height, const uint32_t& width) : _buffer(height, std::vector<char>(width, ' '))
{

}

neo::renderer::RenderBuffer::~RenderBuffer()
{

}

void neo::renderer::RenderBuffer::clear()
{
	for (int y = 0; y < _buffer.size(); y++)
	{
		for (int x = 0; x < _buffer[0].size(); x++)
		{
			_buffer[y][x] = ' ';
		}
	}
}

neo::renderer::RenderBuffer::buf& neo::renderer::RenderBuffer::GetBuffer()
{
	return _buffer;
}
