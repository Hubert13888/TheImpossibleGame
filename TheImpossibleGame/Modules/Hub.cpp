#include "Hub.hpp"

#include "Levels/Menu.hpp"
#include "Levels/Instruction.hpp"
#include "Levels/Level1.hpp"
#include "Levels/Level2.hpp"
#include "Levels/Level3.hpp"
#include "Levels/TheEnd.hpp"

#include <iostream>
/*ModuleShape*/

RenderWindow *ModuleShape::window;
Event *ModuleShape::event;
unsigned int ModuleShape::windowWidth;
unsigned int ModuleShape::windowHeight;
Font ModuleShape::calibri;

unsigned int ModuleShape::deathCounter = 0;

Texture *ModuleShape::topB, *ModuleShape::bottomB, *ModuleShape::leftB, *ModuleShape::rightB,
		*ModuleShape::bottomleftB, *ModuleShape::bottomrightB, *ModuleShape::topleftB, *ModuleShape::toprightB,
		*ModuleShape::player, *ModuleShape::item,
		*ModuleShape::normal, *ModuleShape::start, *ModuleShape::finish, *ModuleShape::checkpoint;

Music *ModuleShape::mainTheme;
bool ModuleShape::mainThemePlays = true;

ModuleShape::ModuleShape() {
	calibri.loadFromFile("Fonts/calibri.ttf");
	topB = new Texture; bottomB = new Texture; leftB = new Texture; rightB = new Texture;
	bottomleftB = new Texture; bottomrightB = new Texture; topleftB = new Texture; toprightB = new Texture;
	player = new Texture; item = new Texture;
	normal = new Texture; start = new Texture; finish = new Texture; checkpoint = new Texture;

	mainTheme = new Music;

	topB->loadFromFile("./Modules/Levels/graphics/items/topB.png");
	bottomB->loadFromFile("./Modules/Levels/graphics/items/bottomB.png");
	leftB->loadFromFile("./Modules/Levels/graphics/items/leftB.png");
	rightB->loadFromFile("./Modules/Levels/graphics/items/rightB.png");

	bottomleftB->loadFromFile("./Modules/Levels/graphics/items/bottomleftB.png");
	bottomrightB->loadFromFile("./Modules/Levels/graphics/items/bottomrightB.png");
	topleftB->loadFromFile("./Modules/Levels/graphics/items/topleftB.png");
	toprightB->loadFromFile("./Modules/Levels/graphics/items/toprightB.png");

	player->loadFromFile("./Modules/Levels/graphics/items/player40.png");
	item->loadFromFile("./Modules/Levels/graphics/items/item.png");

	normal->loadFromFile("./Modules/Levels/graphics/items/normal.png");
	start->loadFromFile("./Modules/Levels/graphics/items/start.png");
	finish->loadFromFile("./Modules/Levels/graphics/items/finish.png");
	checkpoint->loadFromFile("./Modules/Levels/graphics/items/checkpoint.png");

	mainTheme->openFromFile("./Modules/Levels/music/mainTheme.ogg");
}
void ModuleShape::motion() {}
void ModuleShape::events() {}
void ModuleShape::render() {}
void ModuleShape::change(string name) {}

/*Hub*/
string Hub::state = "menu";
bool Hub::newState;
Text Hub::deadText;

Hub::Hub() {
	deadText.setFont(calibri);
	deadText.setFillColor(Color::Red);
	deadText.setPosition(Vector2f(100, 100));

	Hub::newState = false;
		 if (Hub::state == "menu") Menu::Menu();
	else if (Hub::state == "instruction") Instruction::Instruction();
	else if (Hub::state == "level1") Level1::Level1();
	else if (Hub::state == "level2") Level2::Level2();
	else if (Hub::state == "level3") Level3::Level3();
	else if (Hub::state == "theEnd") TheEnd::TheEnd();
}

void Hub::motion() {
	if (Hub::newState) Hub::Hub();

		 if (Hub::state == "menu") Menu::motion();
	else if (Hub::state == "instruction") Instruction::motion();
	else if (Hub::state == "level1") Level1::motion();
	else if (Hub::state == "level2") Level2::motion();
	else if (Hub::state == "level3") Level3::motion();
	else if (Hub::state == "theEnd") TheEnd::motion();
}
void Hub::events() {
	if (event->type == sf::Event::KeyPressed &&
		event->key.code == sf::Keyboard::Escape) Hub::change("menu");

	if (Hub::newState) Hub::Hub();

		 if (Hub::state == "menu") Menu::events();
	else if (Hub::state == "instruction") Instruction::events();
	else if (Hub::state == "level1") Level1::events();
	else if (Hub::state == "level2") Level2::events();
	else if (Hub::state == "level3") Level3::events();
	else if (Hub::state == "theEnd") TheEnd::events();
}
void Hub::render() {
	if (Hub::newState) Hub::Hub();

		 if (Hub::state == "menu") Menu::render();
	else if (Hub::state == "instruction") Instruction::render();
	else if (Hub::state == "level1") Level1::render();
	else if (Hub::state == "level2") Level2::render();
	else if (Hub::state == "level3") Level3::render();
	else if (Hub::state == "theEnd") TheEnd::render();

	if (Hub::state != "menu" && Hub::state != "instruction" && Hub::state != "theEnd") {
		String temp = L"Śmierci: ";
		temp += to_string(deathCounter);
		deadText.setString(temp);
		window->draw(deadText);
	}
}
void Hub::change(string name) {
	Hub::state = name;
	Hub::newState = true;
}
