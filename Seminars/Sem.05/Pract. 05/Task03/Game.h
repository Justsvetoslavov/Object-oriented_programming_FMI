#pragma once

class Game
{
private:
	char* title;
	float price;
	bool isAvailabe;
public:
	Game();
	Game(char* title, float price);
	Game(const Game& other);
	Game& operator=(const Game& other);
	~Game();

	char* getTitle() const;
	float getPrice() const;
	bool getIsAvailable() const;

	void setTitle(char* title);
	void setPrice(float price);

	bool isFree() const;
	void print() const;

private:
	void free();
	void copyFrom(const Game& other);
};