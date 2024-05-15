#pragma once

#include "Game.h"

class TextureManager {

public:
	static SDL_Texture* LoadTexture(const char* fileName);
	static void Draw(SDL_Texture* tec, SDL_Rect src, SDL_Rect dest);
};