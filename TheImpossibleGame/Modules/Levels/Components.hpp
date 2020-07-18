#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include "../Hub.hpp"

struct Opponent {
	CircleShape sprite;
	string label;
	double radius, time, velocity, alreadyMade = 0, w, x, y, a, b;

	Opponent *leader;
};

struct Block {
	Sprite sprite;
	string name;
};

struct Item {
	Sprite sprite;
	bool collected = false;
};

class Components : public ModuleShape {
public:
	Components() {}

	static void squareMove(Sprite &squareS, vector<vector<Block>> &field);
	static void opponentsMove(vector<Opponent> &opponents, Sprite &squareS);
};