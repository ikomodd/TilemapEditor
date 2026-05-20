#pragma once

#include <string>
#include <SDL3/SDL.h>

#include "../Inheritance/Children/Children.h"

class GAME_Node : public GAME_Children {
public:

	std::string Name;

	GAME_Node(std::string name) : Name(name), GAME_Children(this) {}
	virtual ~GAME_Node() {}

	virtual void _Ready() {}
	virtual void _Draw(SDL_Renderer* renderer) {}
	virtual void _Event(SDL_Event& event) {}
	virtual void _Process(float delta) {}
	virtual void _Exit() {}
};