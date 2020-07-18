#include "Instruction.hpp"
#include <iostream>

Texture *Instruction::backgroundT;
Sprite Instruction::background;
Text Instruction::ok;

Instruction::Instruction() {
	backgroundT = new Texture;
	backgroundT->loadFromFile("./Modules/Levels/graphics/background_instruction.png");

	background.setTexture(*backgroundT);

	ok.setFont(calibri);
	ok.setString(L"Jestem Gotów");
	ok.setFillColor(Color(0, 158, 139));
	ok.setPosition(
		Vector2f(windowWidth - 250 - ok.getGlobalBounds().width / 2,
			100));
}

void Instruction::motion() {
	
}

void Instruction::events() {
	if (event->type == sf::Event::KeyPressed)
		if (event->key.code == sf::Keyboard::Enter)
			Hub::change("menu");
}
void Instruction::render() {
	window->draw(background);
	window->draw(ok);
}