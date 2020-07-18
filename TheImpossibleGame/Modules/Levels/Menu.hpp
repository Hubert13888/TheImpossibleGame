#pragma once

#include "../Hub.hpp"

class Menu : public ModuleShape {
public:
	static Texture *backgroundT;
	static Sprite background;
	static Text play, instruction, exit;

	static int selectedOption;

	Menu();

	static void motion();
	static void events();
	static void render();
};