#include "Level1.hpp"
#include "sounds/Sounds.hpp"
#include <iostream>

Texture *Level1::backgroundT;
Sprite Level1::background, Level1::playerS;
vector<vector<Block>> Level1::field(36, vector<Block>(20));
vector<Opponent> Level1::opponents(5);

Level1::Level1() {
	for (auto &opponent : opponents) opponent = {};

	backgroundT = new Texture;
	backgroundT->loadFromFile("./Modules/Levels/graphics/background_level1.png");

	background.setTexture(*backgroundT);

	playerS.setTexture(*player);
	playerS.setPosition(Vector2f(
		100 + 6 * 30,
		90 + 16 * 30
	));

	for (int i = 0; i < 36; i++)
		for (int j = 0; j < 20; j++) {

			if (i == 3 && j > 13 && j < 19) {
				field[i][j].sprite.setTexture(*leftB);
				field[i][j].name = "leftB";
			}
			if (i > 3 && i < 20 && j == 19) {
				field[i][j].sprite.setTexture(*bottomB);
				field[i][j].name = "bottomB";
			}
			if (i == 20 && j < 19 && j > 12) {
				field[i][j].sprite.setTexture(*rightB);
				field[i][j].name = "rightB";
			}
			if (i == 20 && j == 12) {
				field[i][j].sprite.setTexture(*topleftB);
				field[i][j].name = "topleftB";
			}
			if (i > 20 && i < 30 && j == 12) {
				field[i][j].sprite.setTexture(*bottomB);
				field[i][j].name = "bottomB";
			}
			if (i == 30 && j < 12 && j > 5) {
				field[i][j].sprite.setTexture(*rightB);
				field[i][j].name = "rightB";
			}
			if (i < 30 && i>13 && j == 5) {
				field[i][j].sprite.setTexture(*topB);
				field[i][j].name = "topB";
			}
			if (i == 13 && j > 5 && j < 13) {
				field[i][j].sprite.setTexture(*leftB);
				field[i][j].name = "leftB";
			}
			if (i == 13 & j == 13) {
				field[i][j].sprite.setTexture(*bottomrightB);
				field[i][j].name = "bottomrightB";
			}
			if (i < 13 && i>3 && j == 13) {
				field[i][j].sprite.setTexture(*topB);
				field[i][j].name = "topB";
			}

			if (i > 3 && i < 9 && j>13 && j < 19) {
				field[i][j].sprite.setTexture(*start);
				field[i][j].name = "start";
			}
			if (i > 25 && i < 30 && j>5 && j < 12) {
				field[i][j].sprite.setTexture(*finish);
				field[i][j].name = "finish";
			}

			if ((i > 8 && i < 20 && j > 13 && j < 19) ||
				(i > 13 && i < 20 && j > 5 && j < 14) ||
				(i > 19 && i < 26 && j > 5 && j < 12)) {
				field[i][j].sprite.setTexture(*normal);
				field[i][j].name = "normal";
			}
		}
	
	for (int i = 0; i < opponents.size(); i++) {
		opponents[i].sprite.setRadius(12);
		opponents[i].sprite.setOutlineThickness(5);
		opponents[i].sprite.setOutlineColor(Color::Black);
		opponents[i].sprite.setFillColor(Color(0, 82, 214));
	}

	opponents[0].sprite.setPosition(Vector2f(100 + 15 * 30, 90 + 18 * 30));
	opponents[0].label = "linearY";
	opponents[0].velocity = 1;
	opponents[0].radius = 12 * 30;

	opponents[1].sprite.setPosition(Vector2f(100 + 18 * 30, 90 + 6 * 30));
	opponents[1].label = "linearY";
	opponents[1].velocity = -1;
	opponents[1].radius = 12 * 30;

	opponents[2].sprite.setPosition(Vector2f(100 + 24 * 30, 90 + 10 * 30));
	opponents[2].label = "linearX";
	opponents[2].velocity = 0.75;
	opponents[2].radius = 9 * 30;

	opponents[3].sprite.setPosition(Vector2f(100 + 15 * 30, 90 + 7 * 30));
	opponents[3].label = "linearX";
	opponents[3].velocity = -0.75;
	opponents[3].radius = 9 * 30;

	opponents[4].sprite.setPosition(Vector2f(100 + 23 * 30, 90 + 6 * 30));
	opponents[4].label = "linearY";
	opponents[4].velocity = -0.5;
	opponents[4].radius = 5 * 30;
}

void Level1::motion() {

	
	Components::squareMove(playerS, field);

	Components::opponentsMove(opponents, playerS);

	for (int i = 0; i < opponents.size(); i++) {
		if (opponents[i].sprite.getGlobalBounds().intersects(playerS.getGlobalBounds())) {
			Sounds::useHit();
			deathCounter++;
			playerS.setPosition(Vector2f(
				100 + 6 * 30,
				90 + 16 * 30
			));
		}
	}

	/*META*/

	for (int i = 0; i < 36; i++)
		for (int j = 0; j < 20; j++) {
			if (field[i][j].name == "finish"
				&& field[i][j].sprite.getGlobalBounds().intersects(playerS.getGlobalBounds())) {
				Sounds::useGoal();
				Hub::change("level2");
			}
		}
}

void Level1::events() {
}

void Level1::render() {
	window->draw(background);

	for (int i = 0; i < 36; i++)
		for (int j = 0; j < 20; j++) {
			field[i][j].sprite.setPosition(Vector2f(
				100 + i * 30,
				90 + j * 30
			));
			window->draw(field[i][j].sprite);
		}

	window->draw(playerS);

	for (int i = 0; i < opponents.size(); i++) window->draw(opponents[i].sprite);
}