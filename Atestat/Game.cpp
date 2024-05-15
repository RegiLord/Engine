#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"



Map* map;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& player(manager.addEntity());
auto& coin(manager.addEntity());

Game::Game()
{
	xpos = ypos = SDL_WINDOWPOS_CENTERED;
}
Game::~Game()
{}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		std::cout << "Subsystems Initialised!..." << std::endl;
		
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		
		if (window)
			std::cout << "Window Created!..." << std::endl;

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created!...\n";
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}

	map = new Map();

	player.addComponent<PositionComponent>();
	player.addComponent<SpriteComponent>("assets/player.png");
	coin.addComponent<PositionComponent>(400, 400);
	coin.addComponent<SpriteComponent>("assets/coin.png");

	player.getComponent<PositionComponent>().x(100);
}

void Game::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false; 
			break; 
		
		default: break;
	}
}
void Game::update()
{
	manager.refresh();
	manager.update();
}
void Game::render()
{	
	SDL_RenderClear(renderer);
	map->DrawMap();
	manager.draw();
	SDL_RenderPresent(renderer);
}
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned!...\n";
}

