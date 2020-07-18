#include "TheEnd.hpp"
#include <iostream>

Texture *TheEnd::backgroundT;
Sprite TheEnd::background;
Text TheEnd::ok, TheEnd::score;

TheEnd::TheEnd() {
	backgroundT = new Texture;
	backgroundT->loadFromFile("./Modules/Levels/graphics/background_theEnd.png");

	background.setTexture(*backgroundT);

	ok.setFont(calibri);
	ok.setString(L"Powrót do menu");
	ok.setFillColor(Color(0, 158, 139));
	ok.setPosition(
		Vector2f(windowWidth - 200 - ok.getGlobalBounds().width / 2,
			100));

	score.setFont(calibri);
	score.setString(L"Ilość zginięć: " + to_string(deathCounter));
	score.setFillColor(Color::Blue);
	score.setPosition(
		Vector2f(
			(windowWidth - score.getGlobalBounds().width) / 2,
			(windowHeight - score.getGlobalBounds().height) / 2 + 40
		));
}

void TheEnd::motion() {
}

void TheEnd::events() {
	if (event->type == sf::Event::KeyPressed)
		if (event->key.code == sf::Keyboard::Enter)
			Hub::change("menu");
}
void TheEnd::render() {
	window->draw(background);
	window->draw(ok);
	window->draw(score);
}