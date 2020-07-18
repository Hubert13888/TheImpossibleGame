#pragma once

#include "../Hub.hpp"
#include "Components.hpp"
#include <vector>

class Level3 : public ModuleShape {
public:
	static Texture *backgroundT;
	static Sprite background;

	static vector<vector<Block>> field;
	static vector<Opponent> opponents;
	static vector<Item> items;
	static Sprite playerS;

	static float spawnX, spawnY;

	Level3();

	static void motion();
	static void events();
	static void render();
};