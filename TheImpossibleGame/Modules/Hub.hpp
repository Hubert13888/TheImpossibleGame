#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

class ModuleShape {
public:
	static RenderWindow *window;
	static Event *event;

	static unsigned int windowWidth, windowHeight, deathCounter;
	static Font calibri;

	static Texture  *topB, *bottomB, *leftB, *rightB,
					*bottomleftB, *bottomrightB, *topleftB, *toprightB,
					*player, *item, 
					*normal, *start, *finish, *checkpoint;
	static Music *mainTheme;
	static bool mainThemePlays;

	ModuleShape();
	virtual void motion();
	virtual void events();
	virtual void render();

	virtual void change(string nsme);
};

class Hub : public ModuleShape {
public:
	static string state;
	static Text deadText;
	static bool newState;

	Hub();
	static void motion();
	static void events();
	static void render();
	static void change(string name);
};