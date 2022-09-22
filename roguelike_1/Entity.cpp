#include "Entity.hpp"

namespace cyberrogue
{
	Entity::Entity(pos_t pos, renderable_t render_init)
	{
		render = renderable_t {render_init.glyph};
		position = pos_t {pos.x, pos.y};
	}

	Entity::~Entity()
	= default;
}
