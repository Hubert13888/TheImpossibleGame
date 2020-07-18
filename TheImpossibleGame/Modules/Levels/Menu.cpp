#include "Menu.hpp"
#include <iostream>

Texture *Menu::backgroundT;
Sprite Menu::background;
Text Menu::play, Menu::instruction, Menu::exit;

int Menu::selectedOption;

Menu::Menu() {

	selectedOption = 0;

	backgroundT = new Texture;
	backgroundT->loadFromFile("./Modules/Levels/graphics/background_menu.png");

	background.setTexture(*backgroundT);

	play.setFont(calibri);
	instruction.setFont(calibri);
	exit.setFont(calibri);

	play.setString(L"Graj");
	instruction.setString(L"Instrukcja");
	exit.setString(L"Wyjście");

	play.setPosition(
		Vector2f(windowWidth - 250 - play.getGlobalBounds().width / 2,
			320));
	instruction.setPosition(
		Vector2f(windowWidth - 250 - instruction.getGlobalBounds().width / 2,
			420));
	exit.setPosition(
		Vector2f(windowWidth - 250 - exit.getGlobalBounds().width / 2,
			520));
}

void Menu::motion() {
	play.setFillColor(Color(200, 200, 200));
	instruction.setFillColor(Color(200, 200, 200));
	exit.setFillColor(Color(200, 200, 200));
	
	switch (selectedOption) {
		case 0:
			play.setFillColor(Color(0, 158, 139));
			break;
		case 1:
			instruction.setFillColor(Color(0, 158, 139));
			break;
		case 2:
			exit.setFillColor(Color(0, 158, 139));
			break;
	}
}

void Menu::events() {
	if (event->type == sf::Event::KeyPressed) {
		if (event->key.code == sf::Keyboard::Up) {
			if (selectedOption - 1 >= 0) selectedOption -= 1;
		}
		if (event->key.code == sf::Keyboard::Down) {
			if (selectedOption + 1 <= 2) selectedOption += 1;
		}
		if (event->key.code == sf::Keyboard::Enter) {
			switch (selectedOption) {
				case 0:
					deathCounter = 0;
					Hub::change("level1");
					break;
				case 1:
					Hub::change("instruction");
					break;
				case 2:
					window->close();
					break;
			}
		}
	}
}
void Menu::render() {
	window->draw(background);

	window->draw(play);
	window->draw(instruction);
	window->draw(exit);
}