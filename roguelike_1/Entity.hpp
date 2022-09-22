#pragma once
#include "renderable_t.hpp"
#include "pos_t.hpp"

namespace cyberrogue
{
	class Entity
	{
	private:
	public:
		Entity(pos_t pos, renderable_t rend);
		~Entity();

		pos_t position;
		renderable_t render;
	};
}