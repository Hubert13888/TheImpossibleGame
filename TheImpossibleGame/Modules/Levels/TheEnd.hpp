#pragma once

#include "../Hub.hpp"

class TheEnd : public ModuleShape {
public:
	static Texture *backgroundT;
	static Sprite background;
	static Text ok, score;

	TheEnd();

	static void motion();
	static void events();
	static void render();
};