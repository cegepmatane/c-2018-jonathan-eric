#include "pch.h"
#include "Grille.h"


Grille::Grille()
{
	selectedCase = 0;
	for (int height = 0; height < configMap::mapHeight; height++)
	{
		for (int width = 0; width < configMap::mapWidth; width++)
		{
			arrayCase[height][width] = new Case(width, height);
			//cout <<" " << height << "-" << width;
		}
		cout << endl;
	}
}


Grille::~Grille()
{
	for (int height = 0; height < configMap::mapHeight; height++)
	{
		for (int width = 0; width < configMap::mapWidth; width++)
		{
			delete arrayCase[height][width];
		}
	}
}

void Grille::displayConsol(vector<Character*> listCharacter)
{
	update(listCharacter);

	//displayConsol
	for (int height = 0; height < configMap::mapHeight; height++)
	{
		for (int width = 0; width < configMap::mapWidth; width++)
		{
			arrayCase[height][width]->displayConsol();
			//cout << height << height;
		}
		cout << endl;
	}
}

void Grille::update(vector<Character*> listCharacter)
{
	//remove character on case
	for (int height = 0; height < configMap::mapHeight; height++)
	{
		for (int width = 0; width < configMap::mapWidth; width++)
		{
			arrayCase[height][width]->removeCharacterOnCase();
		}
	}

	//change character on case
	for (int indexCharacter = 0; indexCharacter < listCharacter.size(); indexCharacter++)
	{
		arrayCase[(int)listCharacter[indexCharacter]->getVertical()][(int)listCharacter[indexCharacter]->getHorizontal()]->changeCharacter(listCharacter[indexCharacter]);
	}
}

void Grille::display(sf::RenderWindow *window)
{
	for (int height = 0; height < configMap::mapHeight; height++)
	{
		for (int width = 0; width < configMap::mapWidth; width++)
		{
			arrayCase[height][width]->display(window);
			//cout <<" " << height << "-" << width;
		}
	}	
}

void Grille::setCharacterAt(Character *character, int positionVertical, int positionHorizontal)
{
	arrayCase[positionVertical][positionHorizontal]->changeCharacter(character);
}

void Grille::updateDisplay(vector<Character*> listCharacter)
{
	system("cls");
	displayConsol(listCharacter);
}

void Grille::selecteCase(int horizontal, int vertical, Case::TYPE_OF_SELECT typeOfSelection)
{
	if (selectedCase != 0)
		selectedCase->unSelect();
	arrayCase[vertical][horizontal]->select(typeOfSelection);
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

void Grille::loadSpriteAllCharacter()
{
	for (int height = 0; height < configMap::mapHeight; height++)
	{
		for (int width = 0; width < configMap::mapWidth; width++)
		{
			if (arrayCase[height][width]->hasCharacter())
			{
				arrayCase[height][width]->getCharacter()->loadSprite();
			}
			//cout <<" " << height << "-" << width;
		}
	}
}


