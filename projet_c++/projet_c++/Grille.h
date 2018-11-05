#pragma once
#include "Case.h"
#include <SFML/Graphics.hpp>


class Grille
{
public:
	Grille();
	~Grille();
	void displayConsol(vector<Character*> listCharacter);
	void update(vector<Character*> listCharacter);
	void display(sf::RenderWindow * window);
	enum configMap {mapHeight = 12, mapWidth = 18};
	void setCharacterAt(Character *character, int positionVertical, int positionHorizontal);
	void updateDisplay(vector<Character*> listCharacter);
	void selecteCase(int horizontal, int vertical, Case::TYPE_OF_SELECT typeOfSelection);
	//void selecteCase(int horizontaly, int vertical);

	void moveSelectedCaseRight();
	void moveSelectedCaseLeft();
	void moveSelectedCaseUp();
	void moveSelectedCaseDown();

	int getSelectedHorizontal();
	int getSelectedVertical();
	Case *getselectedCase();

	void loadSpriteAllCharacter();


private:
	
	Case *arrayCase[mapHeight][mapWidth];
	Case *selectedCase;
	int selectedCaseVertical;
	int selectedCaseHorizontal;
};

