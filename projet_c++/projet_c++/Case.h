#pragma once

#include "character/Character.h"

class Case
{
public:
	Case();
	~Case();
	void changeCharacter(Character *a_character);
	void removeCharacterOnCase();
	void displayConsol();
	void select();
	void unSelect();

	bool hasCharacter();
	Character *getCharacter();

private:
	Character *characterOnCase;
	bool isSelected;

};

