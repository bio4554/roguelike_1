// roguelike_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Engine.hpp"

int main()
{
	constexpr int WINDOW_WIDTH = 80;
	constexpr int WINDOW_HEIGHT = 50;
	static const std::string WINDOW_TITLE = "libtcod C++ tutorial 1";

	

	cyberrogue::Engine engine = cyberrogue::Engine(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, 0, nullptr);

	engine.RunGame();

	return 0;
}
