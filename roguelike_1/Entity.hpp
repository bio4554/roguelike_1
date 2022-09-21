#pragma once
#include "Renderable.hpp"
#include "Position.hpp"

namespace cyberrogue
{
	class Entity
	{
	private:
	public:
		Entity(pos_t pos, renderable rend);
		~Entity();

		pos_t position;
		renderable render;
	};
}