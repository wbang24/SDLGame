/*
* Wayland Bang 2019
* All of my SDL Learnings are From: https://wiki.libsdl.org/ 
* and Let's Make Games youtube channel : https://www.youtube.com/channel/UCAM9ZPgEIdeHAsmG50wqL1g
*/

//goal of this script was to render my own image with the SDL library

#include "Game.h"

//texture manager class
SDL_Texture* playerTex;

Game::Game(){
//nothing here yet
}

Game::~Game(){
//nothing here yet
}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}

	//loading our sprite from the assets folder
	SDL_Surface* tempSurface = IMG_Load("Assets/SDLSprite.png");
	playerTex = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

}

void Game::handleEvents()
{
	SDL_Event event;

	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
	cnt++;
	std::cout << cnt << std::endl;
}

void Game::render()
{
	//add all our textures to be renderered
	//whatever we pain first will be in the background
	SDL_RenderClear(renderer);
	//so we want our player inbetween
	SDL_RenderCopy(renderer, playerTex, NULL, NULL); //using null for source rect and next rect
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
