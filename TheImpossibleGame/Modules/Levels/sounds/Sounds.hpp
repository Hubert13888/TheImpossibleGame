#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

class Sounds {
public:
	static Sound *hit, *item, *goal, *checkpoint;

	Sounds();
	static void useHit();
	static void useItem();
	static void useGoal();
	static void useCheckpoint();
};