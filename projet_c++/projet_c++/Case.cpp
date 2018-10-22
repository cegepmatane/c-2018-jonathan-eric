#include "pch.h"
#include "Case.h"


Case::Case()
{
}


Case::~Case()
{

}

void Case::changeCharacter(Character *a_character)
{
	this->characterOnCase = a_character;
}

void Case::removeCharacterOnCase()
{
	characterOnCase = 0;
}

void Case::display()
{
	cout << "[";
	if (isSelected)
		cout << ">";
	else
		cout << " ";

	if (characterOnCase != 0)
	{
		characterOnCase->display();
	}
	else
	{
		cout << " ";
	}

	if (isSelected)
		cout << "<";
	else
		cout << " ";

	cout << "]";
}

void Case::select()
{
	isSelected = true;
}

void Case::unSelect()
{
	isSelected = false;
}

bool Case::hasCharacter()
{
	if (characterOnCase != 0)
		return true;

	else
		return false;
}

Character * Case::getCharacter()
{
	return characterOnCase;
}
