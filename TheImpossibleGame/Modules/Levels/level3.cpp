#include "Level3.hpp"
#include "sounds/Sounds.hpp"
#include <iostream>

Texture *Level3::backgroundT;
Sprite Level3::background, Level3::playerS;
vector<vector<Block>> Level3::field(36, vector<Block>(20));
vector<Opponent> Level3::opponents(13);
vector<Item> Level3::items(2);

float Level3::spawnX, Level3::spawnY;

Level3::Level3() {
	spawnX = 100 + 4 * 30;
	spawnY = 90 + 4.5 * 30;

	for (auto &opponent : opponents) opponent = {};
	for (auto &item : items) item = {};

	backgroundT = new Texture;
	backgroundT->loadFromFile("./Modules/Levels/graphics/background_level3.png");

	background.setTexture(*backgroundT);

	playerS.setTexture(*player);
	playerS.setPosition(Vector2f(
		spawnX,
		spawnY
	));

	for (int i = 0; i < 36; i++)
		for (int j = 0; j < 20; j++) {

			if (i == 2 && j > 2 && j < 7) {
				field[i][j].sprite.setTexture(*leftB);
				field[i][j].name = "leftB";
			}
			if (i > 2 && i < 11 && j == 7) {
				field[i][j].sprite.setTexture(*bottomB);
				field[i][j].name = "bottomB";
			}
			if (i == 11 && j == 7) {
				field[i][j].sprite.setTexture(*toprightB);
				field[i][j].name = "toprightB";
			}
			if (i == 11 && j > 7 && j < 16) {
				field[i][j].sprite.setTexture(*leftB);
				field[i][j].name = "leftB";
			}
			if (i > 11 && i < 17 && j == 16) {
				field[i][j].sprite.setTexture(*bottomB);
				field[i][j].name = "bottomB";
			}
			if (i == 17 && j == 16) {
				field[i][j].sprite.setTexture(*toprightB);
				field[i][j].name = "toprightB";
			}
			if (i == 17 && j > 16 && j < 18) {
				field[i][j].sprite.setTexture(*leftB);
				field[i][j].name = "leftB";
			}
			if (i > 17 && i < 21 && j == 18) {
				field[i][j].sprite.setTexture(*bottomB);
				field[i][j].name = "bottomB";
			}
			if (i == 21 && j < 18 && j > 16) {
				field[i][j].sprite.setTexture(*rightB);
				field[i][j].name = "rightB";
			}
			if (i == 21 && j == 16) {
				field[i][j].sprite.setTexture(*topleftB);
				field[i][j].name = "topleftB";
			}
			if (i > 21 && i < 27 && j == 16) {
				field[i][j].sprite.setTexture(*bottomB);
				field[i][j].name = "bottomB";
			}
			if (i == 27 && j < 16 && j>7) {
				field[i][j].sprite.setTexture(*rightB);
				field[i][j].name = "rightB";
			}
			if (i == 27 && j == 7) {
				field[i][j].sprite.setTexture(*topleftB);
				field[i][j].name = "topleftB";
			}
			if (i > 27 && i < 32 && j == 7) {
				field[i][j].sprite.setTexture(*bottomB);
				field[i][j].name = "bottomB";
			}
			if (i == 32 && j > 2 && j < 7) {
				field[i][j].sprite.setTexture(*rightB);
				field[i][j].name = "rightB";
			}
			if (i < 32 && i>18 && j == 2) {
				field[i][j].sprite.setTexture(*topB);
				field[i][j].name = "topB";
			}
			if (i == 18 && j > 2 && j < 11) {
				field[i][j].sprite.setTexture(*leftB);
				field[i][j].name = "leftB";
			}
			if (i > 18 && i < 22 && j == 11) {
				field[i][j].sprite.setTexture(*bottomB);
				field[i][j].name = "bottomB";
			}
			if (i == 22 && j == 11) {
				field[i][j].sprite.setTexture(*toprightB);
				field[i][j].name = "toprightB";
			}
			if (i == 22 && j == 12) {
				field[i][j].sprite.setTexture(*leftB);
				field[i][j].name = "leftB";
			}
			if (i == 22 && j == 13) {
				field[i][j].sprite.setTexture(*bottomrightB);
				field[i][j].name = "bottomrightB";
			}
			if (i < 22 && i>16 && j == 13) {
				field[i][j].sprite.setTexture(*topB);
				field[i][j].name = "topB";
			}
			if (i == 16 && j == 13) {
				field[i][j].sprite.setTexture(*bottomleftB);
				field[i][j].name = "bottomleftB";
			}
			if (i == 16 && j < 13 && j>2) {
				field[i][j].sprite.setTexture(*rightB);
				field[i][j].name = "rightB";
			}
			if (i < 16 && i>2 && j == 2) {
				field[i][j].sprite.setTexture(*topB);
				field[i][j].name = "topB";
			}
			if (i > 2 && i < 6 && j>2 && j < 7) {
				field[i][j].sprite.setTexture(*start);
				field[i][j].name = "start";
			}
			if (i > 28 && i < 32 && j>2 && j < 7) {
				field[i][j].sprite.setTexture(*finish);
				field[i][j].name = "finish";
			}
			if (i > 17 && i < 21 && j>15 && j < 18) {
				field[i][j].sprite.setTexture(*checkpoint);
				field[i][j].name = "checkpoint";
			}
			if ((i >= 6 && i < 16 && j>2 && j < 7) ||
				(i>11 && i<16 && j>=7 && j<16) ||
				(i>=16 && i<27 && j>13 && j<16) ||
				(i>22 && i<27 && j>10 && j<14) ||
				(i>18 && i<27 && j>2 && j<=10)||
				(i>=27 && i<=28 && j>2 && j<7)) {
				field[i][j].sprite.setTexture(*normal);
				field[i][j].name = "normal";
			}
		}

	for (auto &opponent1 : opponents) {
		opponent1.sprite.setRadius(12);
		opponent1.sprite.setOutlineThickness(5);
		opponent1.sprite.setOutlineColor(Color::Black);
		opponent1.sprite.setFillColor(Color(0, 82, 214));
	}

	opponents[0].sprite.setPosition(Vector2f(100 + 13.6 * 30, 90 + 15 * 30));
	opponents[0].label = "linearY";
	opponents[0].velocity = 1;
	opponents[0].radius = 12 * 30;

	opponents[1].sprite.setPosition(Vector2f(100 + 13 * 30, 90 + 5 * 30));
	opponents[2].sprite.setPosition(Vector2f(100 + 15 * 30, 90 + 8.5 * 30));
	opponents[3].sprite.setPosition(Vector2f(100 + 12.2 * 30, 90 + 11 * 30));
	opponents[4].sprite.setPosition(Vector2f(100 + 15 * 30, 90 + 13.2 * 30));

	opponents[5].sprite.setPosition(Vector2f(100 + 22.5 * 30, 90 + 6.5 * 30));

	opponents[6].label = "circled";
	opponents[6].a = 100 + 22.5 * 30;
	opponents[6].b = 90 + 6.5 * 30;
	opponents[6].radius = 1.7 * 30;
	opponents[6].time = 2;

	opponents[7].label = "sticked";
	opponents[7].leader = &opponents[6];
	opponents[7].radius = 3.4 * 30;

	opponents[8].label = "sticked";
	opponents[8].leader = &opponents[6];
	opponents[8].radius = -1.7 * 30;

	opponents[9].label = "sticked";
	opponents[9].leader = &opponents[6];
	opponents[9].radius = -3.4 * 30;

	opponents[10].sprite.setPosition(Vector2f(100 + 27 * 30, 90 + 4 * 30));
	opponents[11].sprite.setPosition(Vector2f(100 + 26 * 30, 90 + 8 * 30));
	opponents[12].sprite.setPosition(Vector2f(100 + 27 * 30, 90 + 4 * 30));


	for (auto &item1 : items) item1.sprite.setTexture(*item);

	items[0].sprite.setPosition(Vector2f(100 + 19.5 * 30, 90 + 3.3 * 30));
	items[1].sprite.setPosition(Vector2f(100 + 19.5 * 30, 90 + 9.7 * 30));
}

void Level3::motion() {

	Components::squareMove(playerS, field);

	Components::opponentsMove(opponents, playerS);

	for (int i = 0; i < opponents.size(); i++) {
		if (opponents[i].sprite.getGlobalBounds().intersects(playerS.getGlobalBounds())) {
			for (auto &item : items) item.collected = false;
			deathCounter++;
			Sounds::useHit();
			playerS.setPosition(Vector2f(
				spawnX,
				spawnY
			));
		}
	}

	for (auto &item1 : items) 
		if (item1.sprite.getGlobalBounds().intersects(playerS.getGlobalBounds())) {
			if (!item1.collected) Sounds::useItem();
			item1.collected = true;
		}

	/*META I CHECKPOINT*/

	for (int i = 0; i < 36; i++)
		for (int j = 0; j < 20; j++) {
			if (field[i][j].sprite.getGlobalBounds().intersects(playerS.getGlobalBounds())) {
				if (field[i][j].name == "finish") {
					bool allCollected = true;
					for (auto &item : items) if (!item.collected) allCollected = false;
					if (allCollected) {
						Sounds::useGoal();
						Hub::change("theEnd");
					}
				}
				if (field[i][j].name == "checkpoint") {
					if (spawnX != 100 + 18.9 * 30 && spawnY != 90 + 16.5 * 30) {
						Sounds::useCheckpoint();
						spawnX = 100 + 18.9 * 30;
						spawnY = 90 + 16.5 * 30;
					}
				}
			}
		}
}

void Level3::events() {
}

void Level3::render() {
	window->draw(background);

	for (int i = 0; i < 36; i++)
		for (int j = 0; j < 20; j++) {
			field[i][j].sprite.setPosition(Vector2f(
				100 + i * 30,
				90 + j * 30
			));
			window->draw(field[i][j].sprite);
		}

	for (auto item1 : items) if (!item1.collected) window->draw(item1.sprite);

	window->draw(playerS);

	for (auto opponent1 : opponents) window->draw(opponent1.sprite);
}