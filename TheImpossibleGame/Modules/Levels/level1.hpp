#pragma once

#include "../Hub.hpp"
#include "Components.hpp"
#include <vector>

class Level1 : public ModuleShape {
public:
	static Texture *backgroundT;
	static Sprite background;

	static vector<vector<Block>> field;
	static vector<Opponent> opponents;
	static Sprite playerS;

	Level1();

	static void motion();
	static void events();
	static void render();
};