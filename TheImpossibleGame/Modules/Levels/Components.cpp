#include "Components.hpp"
#include <iostream>

void Components::squareMove(Sprite &playerS, vector<vector<Block>> &field) {

	/*PORUSZANIE SIĘ*/

	bool upFlag = true, downFlag = true, leftFlag = true, rightFlag = true;

	if (event->type == sf::Event::KeyPressed || event->type == sf::Event::KeyReleased) {
		
		float xp = playerS.getPosition().x;
		float yp = playerS.getPosition().y;
		float wp = playerS.getGlobalBounds().width;
		float hp = playerS.getGlobalBounds().height;

		int iBegin = floor((xp - 100) / 30);
		int jBegin = floor((yp - 90) / 30);

		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			for (int i = iBegin - 1; i <= iBegin + 1; i++) {
				if (i >= 0 && i < 36)
					for (int j = jBegin - 1; j <= jBegin + 1; j++) {
						if (j < 0 && j > 20) continue;

						float xs = field[i][j].sprite.getPosition().x;
						float ys = field[i][j].sprite.getPosition().y;
						float ws = field[i][j].sprite.getGlobalBounds().width;
						float hs = field[i][j].sprite.getGlobalBounds().height;

						if (yp <= ys + hs && xp + wp >= xs + 0.3 && xp + 0.3 <= xs + ws &&
							(field[i][j].name == "topB"
								|| field[i][j].name == "bottomrightB"
								|| field[i][j].name == "bottomleftB")) upFlag = false;
					}
			}

		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			for (int i = iBegin - 1; i <= iBegin + 1; i++) {
				if (i >= 0 && i < 36)
					for (int j = jBegin - 1; j <= jBegin + 2; j++) {

						if (j < 0 && j > 20) continue;

						float xs = field[i][j].sprite.getPosition().x;
						float ys = field[i][j].sprite.getPosition().y;
						float ws = field[i][j].sprite.getGlobalBounds().width;

						if (yp + hp >= ys && xp + wp >= xs + 0.3 && xp + 0.4 <= xs + ws &&
							(field[i][j].name == "bottomB"
								|| field[i][j].name == "topleftB"
								|| field[i][j].name == "toprightB")) downFlag = false;
					}
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			for (int i = iBegin - 1; i <= iBegin + 1; i++) {
				if (i >= 0 && i < 36)
					for (int j = jBegin - 1; j <= jBegin + 1; j++) {

						if (j < 0 && j > 20) continue;

						float xs = field[i][j].sprite.getPosition().x;
						float ys = field[i][j].sprite.getPosition().y;
						float ws = field[i][j].sprite.getGlobalBounds().width;
						float hs = field[i][j].sprite.getGlobalBounds().height;

						if (xp <= xs + ws && yp + 0.3 <= ys + hs && yp + hp >= ys + 0.3 &&
							(field[i][j].name == "leftB"
								|| field[i][j].name == "bottomrightB"
								|| field[i][j].name == "toprightB")) leftFlag = false;
					}
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			for (int i = iBegin - 1; i <= iBegin + 2; i++) {
				if (i >= 0 && i < 36)
					for (int j = jBegin - 1; j <= jBegin + 1; j++) {

						if (j < 0 && j > 20) continue;

						float xs = field[i][j].sprite.getPosition().x;
						float ys = field[i][j].sprite.getPosition().y;
						float ws = field[i][j].sprite.getGlobalBounds().width;
						float hs = field[i][j].sprite.getGlobalBounds().height;

						if (xp + hp >= xs && yp + 0.4 <= ys + hs && yp + hp >= ys + 0.4 &&
							(field[i][j].name == "rightB"
								|| field[i][j].name == "topleftB"
								|| field[i][j].name == "bottomleftB")) rightFlag = false;
					}
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Up) && upFlag) {
			if (Keyboard::isKeyPressed(Keyboard::Left) && leftFlag)
				playerS.move(Vector2f(-0.35, -0.35));
			else if (Keyboard::isKeyPressed(Keyboard::Right) && rightFlag)
				playerS.move(Vector2f(0.35, -0.35));

			else playerS.move(Vector2f(0, -0.35));
		}

		else if (Keyboard::isKeyPressed(Keyboard::Down) && downFlag) {
			if (Keyboard::isKeyPressed(Keyboard::Left) && leftFlag)
				playerS.move(Vector2f(-0.35, 0.35));
			else if (Keyboard::isKeyPressed(Keyboard::Right) && rightFlag)
				playerS.move(Vector2f(0.35, 0.35));

			else playerS.move(Vector2f(0, 0.35));
		}

		else if (Keyboard::isKeyPressed(Keyboard::Left) && leftFlag)
			playerS.move(Vector2f(-0.35, 0));

		else if (Keyboard::isKeyPressed(Keyboard::Right) && rightFlag)
			playerS.move(Vector2f(0.35, 0));
	}
}

void Components::opponentsMove(vector<Opponent>& opponents, Sprite & playerS) {

	/*RUCH I INTERAKCJA Z PRZECIWNIKAMI*/

	for (int i = 0; i < opponents.size(); i++) {
		if (opponents[i].label == "linearX") {
			if (opponents[i].alreadyMade < opponents[i].radius) {
				opponents[i].sprite.move(Vector2f(-opponents[i].velocity, 0));
				opponents[i].alreadyMade += abs(opponents[i].velocity);
			}
			else if (opponents[i].alreadyMade >= opponents[i].radius) {
				opponents[i].velocity = -opponents[i].velocity;
				opponents[i].alreadyMade = opponents[i].alreadyMade - opponents[i].radius;
			}
		}

		if (opponents[i].label == "linearY") {
			if (opponents[i].alreadyMade < opponents[i].radius) {
				opponents[i].sprite.move(Vector2f(0, -opponents[i].velocity));
				opponents[i].alreadyMade += abs(opponents[i].velocity);
			}
			else if (opponents[i].alreadyMade >= opponents[i].radius) {
				opponents[i].velocity = -opponents[i].velocity;
				opponents[i].alreadyMade = opponents[i].alreadyMade - opponents[i].radius;
			}
		}

		if (opponents[i].label == "circled") {
			double Vk = 2 * M_PI / opponents[i].time;
			opponents[i].w += Vk * 0.002;

			opponents[i].sprite.setPosition(Vector2f(
				cos(opponents[i].w)*opponents[i].radius+opponents[i].a + opponents[i].x,
				sin(opponents[i].w)*opponents[i].radius+opponents[i].b + opponents[i].y
			));
		}

		if (opponents[i].label == "sticked") {
			opponents[i].sprite.setPosition(Vector2f(
				cos(opponents[i].leader->w)*opponents[i].radius + opponents[i].leader->a + opponents[i].x,
				sin(opponents[i].leader->w)*opponents[i].radius + opponents[i].leader->b + opponents[i].y
			));
		}
	}
}
