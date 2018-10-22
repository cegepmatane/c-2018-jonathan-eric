#pragma once
#include "Case.h"

class Grille
{
public:
	Grille();
	~Grille();
	void display(vector<Character*> listCharacter);
	enum configMap {mapWidth = 10, mapHeight = 10};
	void setCharacterAt(Character *character, int positionVertical, int positionHorizontal);
	void updateDisplay(vector<Character*> listCharacter);
	void selecteCase(int horizontaly, int vertical);

	void moveSelectedCaseRight();
	void moveSelectedCaseLeft();
	void moveSelectedCaseUp();
	void moveSelectedCaseDown();

	int getSelectedHorizontal();
	int getSelectedVertical();
	Case *getselectedCase();

private:
	
	Case *arrayCase[mapHeight][mapWidth];
	Case *selectedCase;
	int selectedCaseVertical;
	int selectedCaseHorizontal;
};

