#include "Game.h"
#include <iostream>

Game::Game()
{
	std::cout << "Game instance created !\n";
}

Game::~Game()
{
	std::cout << "Game destructeur call ! \n";
}

void Game::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cerr << "Error Initializing SDL.\n";
		exit(EXIT_FAILURE);
	}

	m_window = SDL_CreateWindow(NULL,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		800,
		600,
		SDL_WINDOW_BORDERLESS);

	if (!m_window)
	{
		std::cerr << "Error creating SDL Window.\n";
		exit(EXIT_FAILURE);
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, 0);
	if (!m_renderer)
	{
		std::cerr << "Error creating renderer SDL Window.\n";
		exit(EXIT_FAILURE);
	}

	m_isRunning = true;
}

void Game::Run()
{
	while (m_isRunning)
	{
		Game::ProcessInput();
		Game::Update();
		Game::Render();
	}
}

void Game::ProcessInput()
{
	SDL_Event sdlEvent;
	while (SDL_PollEvent(&sdlEvent))
	{
		switch (sdlEvent.type)
		{
		case SDL_QUIT : 
			m_isRunning = false;
			break;
		case SDL_KEYDOWN: 
			if (sdlEvent.key.keysym.sym == SDLK_ESCAPE)
				m_isRunning = false;
			break;
		}
	}
}

void Game::Update()
{

	//Todo Update game object ...

}

void Game::Render()
{
	SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
	SDL_RenderClear(m_renderer);

	//Todo Render all game object ...

	SDL_RenderPresent(m_renderer);
}

void Game::Destroy()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}
