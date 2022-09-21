#include "Entity.hpp"

namespace cyberrogue
{
	Entity::Entity(pos_t pos, renderable render_init)
	{
		render = renderable {render_init.glyph};
		position = pos_t {pos.x, pos.y};
	}

	Entity::~Entity()
	= default;
}
