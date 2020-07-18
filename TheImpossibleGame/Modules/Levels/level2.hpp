#pragma once

#include "../Hub.hpp"
#include "Components.hpp"
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>

class Level2 : public ModuleShape {
public:
	static Texture *backgroundT;
	static Sprite background;

	static vector<vector<Block>> field;
	static vector<Opponent> opponents;
	static vector<Item> items;
	static Sprite playerS;

	Level2();

	static void motion();
	static void events();
	static void render();
};