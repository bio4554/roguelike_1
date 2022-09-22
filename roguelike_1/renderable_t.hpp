#pragma once
#include <string>

namespace cyberrogue
{
	struct renderable_t
	{
		std::string glyph;
		renderable_t() { glyph = ""; }
		renderable_t(std::string s) { glyph = s; }
	};
}
