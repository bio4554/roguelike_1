// roguelike_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Engine.hpp"

int main()
{
	constexpr int WINDOW_WIDTH = 80;
	constexpr int WINDOW_HEIGHT = 50;
	static const std::string WINDOW_TITLE = "libtcod C++ tutorial 1";

	

	cyberrogue::Engine::current = cyberrogue::Engine(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, 0, nullptr);

	//cyberrogue::Engine::current = 0;

	while (engine.IsRunning())
	{
		engine.ProcessSystems();
		engine.HandleEvents();
		engine.Render();
	}

	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
