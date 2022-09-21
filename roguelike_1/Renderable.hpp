#pragma once
#include <string>

namespace cyberrogue
{
	struct renderable
	{
		std::string glyph;
		renderable() { glyph = ""; }
		renderable(std::string s) { glyph = s; }
	};
}
