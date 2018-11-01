#pragma once

#include "character/Character.h"
#include <SFML/Graphics.hpp>


class Case
{
public:
	//Case();
	Case(float posX, float posY);
	~Case();
	void changeCharacter(Character *a_character);
	void removeCharacterOnCase();
	void displayConsol();
	void select();
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

	float m_PosX, m_PosY;


};

