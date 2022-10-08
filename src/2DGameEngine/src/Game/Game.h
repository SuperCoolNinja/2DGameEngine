#pragma once

#include <SDL.h>

class Game
{
public :
	Game();
	~Game();

	void Init();
	void Run();
	void Destroy();


private :
	bool m_isRunning{false};
	SDL_Window* m_window{nullptr};
	SDL_Renderer* m_renderer{nullptr};

	void ProcessInput();
	void Update();
	void Render();

};

