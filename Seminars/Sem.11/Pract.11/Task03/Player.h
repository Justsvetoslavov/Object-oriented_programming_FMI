#pragma once

enum class Star {
	first, 
	second,
	third,
	fourth,
	fifth
};

class Player {
protected:
	int _ID = 0;
	double _points = 0;
	Star _star = Star::first;

public:
	Player() = default;
	Player(int ID);

	virtual bool levelUp();
};