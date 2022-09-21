#include "Graphics.hpp"

#include <iostream>
#include <SDL2/SDL_video.h>

namespace cyberrogue
{
	Graphics::Graphics(int width, int height, const std::string& title, int argc, char* argv[], MessageBus* messageBus) : BusNode(messageBus)
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
		std::cout << "Graphics received message: " << message.getEvent() << std::endl;
	}

	void Graphics::render()
	{
		TCOD_console_clear(mainConsole.get());

		mainContext.present(mainConsole);
	}

	void Graphics::nUpdate()
	{
		
	}

}
