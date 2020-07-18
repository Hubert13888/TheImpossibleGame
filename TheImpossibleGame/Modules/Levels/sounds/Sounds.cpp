#include "Sounds.hpp"
#include "SFML/Audio.hpp"
#include <iostream>

Sound *Sounds::hit, *Sounds::item, *Sounds::goal, *Sounds::checkpoint;

Sounds::Sounds() {
	hit = new Sound;
	item = new Sound;
	goal = new Sound;
	checkpoint = new Sound;
}

void Sounds::useHit() {
	SoundBuffer *buf;
	buf = new SoundBuffer;
	buf->loadFromFile("./Modules/Levels/sounds/hit.ogg");

	hit->setBuffer(*buf);
	hit->play();
}

void Sounds::useItem() {
	SoundBuffer *buf;
	buf = new SoundBuffer;
	buf->loadFromFile("./Modules/Levels/sounds/item.ogg");

	item->setBuffer(*buf);
	item->play();
}

void Sounds::useGoal() {
	SoundBuffer *buf;
	buf = new SoundBuffer;
	buf->loadFromFile("./Modules/Levels/sounds/goal.ogg");

	goal->setBuffer(*buf);
	goal->play();
}

void Sounds::useCheckpoint() {
	SoundBuffer *buf;
	buf = new SoundBuffer;
	buf->loadFromFile("./Modules/Levels/sounds/checkpoint.ogg");

	checkpoint->setBuffer(*buf);
	checkpoint->play();
}

