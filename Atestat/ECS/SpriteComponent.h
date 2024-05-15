#pragma once

#include "Components.h"
#include "../TextureManager.h"

class SpriteComponent : public Component {

private:

	PositionComponent* position;
	SDL_Texture* sprite;
	SDL_Rect src, dest;

public:

	SpriteComponent() = default;
	SpriteComponent(const char* path)
	{
		setTex(path);
	}
	
	void setTex(const char* path)
	{
		sprite = TextureManager::LoadTexture(path);
	}

	void init() override
	{
		position = &entity->getComponent<PositionComponent>();

		src.x = src.y = 0;
		src.w = src.h = 32;

		dest.x = position->x();
		dest.y = position->y();
		dest.w = dest.h = 64;
	}

	void update() override
	{
		dest.x = position->x();
		dest.y = position->y();
	}
		
	void draw() override
	{
		TextureManager::Draw(sprite, src, dest);
	}
};