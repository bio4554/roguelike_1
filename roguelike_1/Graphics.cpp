#include "Graphics.hpp"

#include <iostream>
#include <SDL2/SDL_video.h>

namespace cyberrogue
{
	Graphics::Graphics(int width, int height, const std::string& title, int argc, char* argv[], MessageBus* messageBus) : System(messageBus)
	{
		mainConsole = tcod::Console(width, height);
		auto params = TCOD_ContextParams{};
		params.tcod_version = TCOD_COMPILEDVERSION;  // This is required.
		params.console = mainConsole.get();  // Derive the window size from the console size.
		params.window_title = title.c_str();
		params.sdl_window_flags = SDL_WINDOW_RESIZABLE;
		params.vsync = true;
		params.argc = argc;  // This allows some user-control of the context.
		params.argv = argv;

		mainContext = tcod::Context(params);
	}

	void Graphics::onNotify(Message message)
	{
#ifdef _DEBUG
		//std::cout << "Graphics received message: " << message.getType() << std::endl;
#endif
		std::string type = message.getType();
		std::map<std::string, std::string> data = message.getData();

		if(type == "DRAW_CHAR")
		{
			drawAt(std::stoi(data["x"]), std::stoi(data["y"]), data["str"]);
		}
	}

	void Graphics::render()
	{
		mainContext.present(mainConsole);
	}

	void Graphics::clear()
	{
		TCOD_console_clear(mainConsole.get());
	}


	void Graphics::update()
	{
		std::cout << "Update Graphics" << std::endl;
	}

	void Graphics::drawAt(int x, int y, std::string str)
	{
		tcod::print(mainConsole, { x,y }, str, std::nullopt, std::nullopt);
	}

}
