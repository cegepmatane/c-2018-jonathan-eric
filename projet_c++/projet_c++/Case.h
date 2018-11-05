#pragma once

#include "character/Character.h"
#include <SFML/Graphics.hpp>


class Case
{
public:
	//Case();
	Case(float posX, float posY);
	~Case();

	enum TYPE_OF_SELECT : int { caseSelect, caseTarget, caseUnselected };


	void changeCharacter(Character *a_character);
	void removeCharacterOnCase();
	void displayConsol();
	void select(TYPE_OF_SELECT selectionType);
	//void select(int typeOfSelection);
	//void select();
	void unSelect();
	void display(sf::RenderWindow* window);



	bool hasCharacter();
	Character *getCharacter();

	sf::Sprite* getTexture();

private:
	float WIDTH = 32;
	float HEIGHT = 32;
	Character *characterOnCase;
	bool isSelected;
	sf::Sprite *sprite;
	sf::Texture textureCase;

	sf::Sprite *spriteSelect;
	sf::Texture textureSelect;

	string PATH_CASE_SELECTE;
	string PATH_CASE_TARGET;

	float m_PosX, m_PosY;

	int typeOfSelection;


};

