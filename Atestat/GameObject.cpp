#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, int x, int y)
{
	objTex = TextureManager::LoadTexture(textureSheet);

	xpos = x;
	ypos = y;
}

GameObject::~GameObject()
{}

void GameObject::Update()
{
	xpos++;
	ypos++;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 32;
	srcRect.h = 32;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.h = srcRect.h * 2;
	destRect.w = srcRect.w * 2;
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTex, &srcRect, &destRect);
}