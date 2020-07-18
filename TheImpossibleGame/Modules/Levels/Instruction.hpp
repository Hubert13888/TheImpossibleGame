#pragma once

#include "../Hub.hpp"

class Instruction : public ModuleShape {
public:
	static Texture *backgroundT;
	static Sprite background;
	static Text ok;

	Instruction();

	static void motion();
	static void events();
	static void render();
};