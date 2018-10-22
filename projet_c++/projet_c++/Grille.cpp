#include "pch.h"
#include "Grille.h"


Grille::Grille()
{
	selectedCase = 0;
	for (int width = 0; width < configMap::mapWidth; width++)
	{
		for (int height = 0; height < configMap::mapHeight; height++)
		{
			arrayCase[width][height] = new Case();
			cout <<" " << width << "-" << height;
		}
		cout << endl;
	}
}


Grille::~Grille()
{
	for (int width = 0; width < configMap::mapWidth; width++)
	{
		for (int height = 0; height < configMap::mapHeight; height++)
		{
			delete arrayCase[width][height];
		}
	}
}

void Grille::display(vector<Character*> listCharacter)
{
	//remove character on case
	for (int width = 0; width < configMap::mapWidth; width++)
	{
		for (int height = 0; height < configMap::mapHeight; height++)
		{
			arrayCase[width][height]->removeCharacterOnCase();
		}
	}

	//change character on case
	for (int indexCharacter = 0; indexCharacter < listCharacter.size(); indexCharacter++)
	{
		arrayCase[(int)listCharacter[indexCharacter]->getVertical()][(int)listCharacter[indexCharacter]->getHorizontal()]->changeCharacter(listCharacter[indexCharacter]);
	}

	//display
	for (int width = 0; width < configMap::mapWidth; width++)
	{
		for (int height = 0; height < configMap::mapHeight; height++)
		{
			arrayCase[width][height]->display();
			//cout << width << height;
		}
		cout << endl;
	}
}

void Grille::setCharacterAt(Character *character, int positionVertical, int positionHorizontal)
{
	arrayCase[positionVertical][positionHorizontal]->changeCharacter(character);
}

void Grille::updateDisplay(vector<Character*> listCharacter)
{
	system("cls");
	display(listCharacter);
}

void Grille::selecteCase(int horizontal, int vertical)
{
	if (selectedCase != 0)
		selectedCase->unSelect();
	arrayCase[vertical][horizontal]->select();
	selectedCase = (Case*)arrayCase[vertical][horizontal];
	selectedCaseHorizontal = horizontal;
	selectedCaseVertical = vertical;
}

void Grille::moveSelectedCaseRight()
{
	selectedCaseHorizontal++;
}

void Grille::moveSelectedCaseLeft()
{
	selectedCaseHorizontal--;
}

void Grille::moveSelectedCaseUp()
{
	selectedCaseVertical--;
}

void Grille::moveSelectedCaseDown()
{
	selectedCaseVertical++;
}

int Grille::getSelectedHorizontal()
{
	return selectedCaseHorizontal;
}

int Grille::getSelectedVertical()
{
	return selectedCaseVertical;
}

Case * Grille::getselectedCase()
{
	return arrayCase[selectedCaseVertical][selectedCaseHorizontal];
}
