#pragma once
#include "Case.h"

class Grille
{
public:
	Grille();
	~Grille();
	void displayConsol(vector<Character*> listCharacter);
	enum configMap {mapHeight = 12, mapWidth = 18};
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

