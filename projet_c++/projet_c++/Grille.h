#pragma once
#include "Case.h"

class Grille
{
public:
	Grille();
	~Grille();
	void display(vector<Character*> listCharacter);
	enum configMap {mapWidth = 10, mapHeight = 10};
	void setCharacterAt(Character *character, int positionX, int positionY);
	void updateDisplay(vector<Character*> listCharacter);
	void selecteCase(int x, int y);


private:
	Case *arrayCase[mapWidth][mapHeight];
	Case *selectedCase;
};

