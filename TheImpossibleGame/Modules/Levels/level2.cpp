#include "Level2.hpp"
#include "sounds/Sounds.hpp"
#include <iostream>

Texture *Level2::backgroundT;
Sprite Level2::background, Level2::playerS;
vector<vector<Block>> Level2::field(36, vector<Block>(20));
vector<Opponent> Level2::opponents(12);
vector<Item> Level2::items(3);

Level2::Level2() {
	for (auto &opponent : opponents) opponent = {};
	for (auto &item : items) item = {};

	backgroundT = new Texture;
	backgroundT->loadFromFile("./Modules/Levels/graphics/background_level2.png");

	background.setTexture(*backgroundT);

	playerS.setTexture(*player);
	playerS.setPosition(Vector2f(
		100 + 5 * 30,
		90 + 8.5 * 30
	));

	for (int i = 0; i < 36; i++)
		for (int j = 0; j < 20; j++) {

			if (i == 3 && j > 5 && j < 12) {
				field[i][j].sprite.setTexture(*leftB);
				field[i][j].name = "leftB";
			}

			if (i > 3 && i < 10 && j == 12) {
				field[i][j].sprite.setTexture(*bottomB);
				field[i][j].name = "bottomB";
			}
			
			if (i == 10 && j == 12) {
				field[i][j].sprite.setTexture(*toprightB);
				field[i][j].name = "toprightB";
			}

			if (i == 10 && j > 12 && j < 18) {
				field[i][j].sprite.setTexture(*leftB);
				field[i][j].name = "leftB";
			}

			if (i > 10 && i < 25 && j == 18) {
				field[i][j].sprite.setTexture(*bottomB);
				field[i][j].name = "bottomB";
			}

			if (i == 25 && j < 18 && j > 12) {
				field[i][j].sprite.setTexture(*rightB);
				field[i][j].name = "rightB";
			}

			if (i == 25 && j == 12) {
				field[i][j].sprite.setTexture(*topleftB);
				field[i][j].name = "topleftB";
			}

			if (i > 25 && i < 32 && j == 12) {
				field[i][j].sprite.setTexture(*bottomB);
				field[i][j].name = "bottomB";
			}

			if (i == 32 && j < 12 && j > 5) {
				field[i][j].sprite.setTexture(*rightB);
				field[i][j].name = "rightB";
			}

			if (i < 32 && i > 20 && j == 5) {
				field[i][j].sprite.setTexture(*topB);
				field[i][j].name = "topB";
			}

			if (i == 20 && j > 5 && j < 11) {
				field[i][j].sprite.setTexture(*leftB);
				field[i][j].name = "leftB";
			}

			if (i == 20 && j == 11) {
				field[i][j].sprite.setTexture(*bottomrightB);
				field[i][j].name = "bottomrightB";
			}

			if (i < 20 && i > 15 && j == 11) {
				field[i][j].sprite.setTexture(*topB);
				field[i][j].name = "topB";
			}

			if (i == 15 && j == 11) {
				field[i][j].sprite.setTexture(*bottomleftB);
				field[i][j].name = "bottomleftB";
			}

			if (i == 15 && j < 11 && j > 5) {
				field[i][j].sprite.setTexture(*rightB);
				field[i][j].name = "rightB";
			}

			if (i < 15 && i>3 && j == 5) {
				field[i][j].sprite.setTexture(*topB);
				field[i][j].name = "topB";
			}

			if (i > 3 && i < 7 && j>5 && j < 12) {
				field[i][j].sprite.setTexture(*start);
				field[i][j].name = "start";
			}

			if (i > 28 && i < 32 && j>5 && j < 12) {
				field[i][j].sprite.setTexture(*finish);
				field[i][j].name = "finish";
			}

			if ((i >= 7 && i < 15 && j>5 && j < 12) ||
				(i >= 15 && i < 20 && j>11 && j < 12) ||
				(i > 10 && i < 25 && j >= 12 && j < 18) ||
				(i > 20 && i <= 28 && j > 5 && j < 12)) {
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

	opponents[0].label = "circled";
	opponents[0].a = 100 + 17.5 * 30;
	opponents[0].b = 90 + 8 * 30;
	opponents[0].radius = 2 * 30;
	opponents[0].time = 3;

	opponents[1].label = "sticked";
	opponents[1].leader = &opponents[0];
	opponents[1].radius = 6 * 30;

	opponents[2].label = "sticked";
	opponents[2].leader = &opponents[0];
	opponents[2].radius = 10 * 30;

	opponents[3].label = "sticked";
	opponents[3].leader = &opponents[0];
	opponents[3].radius = -2 * 30;

	opponents[4].label = "sticked";
	opponents[4].leader = &opponents[0];
	opponents[4].radius = -6 * 30;

	opponents[5].label = "sticked";
	opponents[5].leader = &opponents[0];
	opponents[5].radius = -10 * 30;

	opponents[6].label = "circled";
	opponents[6].a = 100 + 17.5 * 30;
	opponents[6].b = 90 + 8 * 30;
	opponents[6].w = M_PI/2;
	opponents[6].radius = 2 * 30;
	opponents[6].time = 3;

	opponents[7].label = "sticked";
	opponents[7].leader = &opponents[6];
	opponents[7].radius = 6 * 30;

	opponents[8].label = "sticked";
	opponents[8].leader = &opponents[6];
	opponents[8].radius = 10 * 30;

	opponents[9].label = "sticked";
	opponents[9].leader = &opponents[6];
	opponents[9].radius = -2 * 30;

	opponents[10].label = "sticked";
	opponents[10].leader = &opponents[6];
	opponents[10].radius = -6 * 30;

	opponents[11].label = "sticked";
	opponents[11].leader = &opponents[6];
	opponents[11].radius = -10 * 30;

	for (auto &item1 : items) item1.sprite.setTexture(*item);

	items[0].sprite.setPosition(Vector2f(100 + 12 * 30, 90 + 16 * 30));
	items[1].sprite.setPosition(Vector2f(100 + 23 * 30, 90 + 16 * 30));
	items[2].sprite.setPosition(Vector2f(100 + 13.5 * 30, 90 + 6.5 * 30));
}

void Level2::motion() {


	Components::squareMove(playerS, field);

	Components::opponentsMove(opponents, playerS);

	for (int i = 0; i < opponents.size(); i++) {
		if (opponents[i].sprite.getGlobalBounds().intersects(playerS.getGlobalBounds())) {
			for (auto &item : items) item.collected = false;
			deathCounter++;
			Sounds::useHit();
			playerS.setPosition(Vector2f(
				100 + 5 * 30,
				90 + 8.5 * 30
			));
		}
	}

	for (auto &item1 : items) if (item1.sprite.getGlobalBounds().intersects(playerS.getGlobalBounds())) { 
		if(!item1.collected) Sounds::useItem();
		item1.collected = true; 
	}

	/*META*/
	
	for (int i = 0; i < 36; i++)
		for (int j = 0; j < 20; j++) {
			if (field[i][j].name == "finish"
				&& field[i][j].sprite.getGlobalBounds().intersects(playerS.getGlobalBounds())) {
					bool allCollected = true;
					for (auto &item : items) if (!item.collected) allCollected = false;
					if (allCollected) {
						Sounds::useGoal();
						Hub::change("level3");
					}
			}
		}
}

void Level2::events() {
}

void Level2::render() {
	window->draw(background);

	for (int i = 0; i < 36; i++)
		for (int j = 0; j < 20; j++) {
			field[i][j].sprite.setPosition(Vector2f(
				100 + i * 30,
				90 + j * 30
			));
			window->draw(field[i][j].sprite);
		}

	for (auto item1 : items) if(!item1.collected) window->draw(item1.sprite);

	window->draw(playerS);

	for (auto opponent1 : opponents) window->draw(opponent1.sprite);
}