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
		arrayCase[(int)listCharacter[indexCharacter]->getX()][(int)listCharacter[indexCharacter]->getY()]->changeCharacter(listCharacter[indexCharacter]);
	}

	//display
	for (int width = 0; width < configMap::mapWidth; width++)
	{
		for (int height = 0; height < configMap::mapHeight; height++)
		{
			arrayCase[width][height]->display();
		}
		cout << endl;
	}
}

void Grille::setCharacterAt(Character *character, int positionX, int positionY)
{
	arrayCase[positionX][positionY]->changeCharacter(character);
}

void Grille::updateDisplay(vector<Character*> listCharacter)
{
	system("cls");
	display(listCharacter);
}

void Grille::selecteCase(int x, int y)
{
	if (selectedCase != 0)
		selectedCase->unSelect();
	arrayCase[x][y]->select();
	selectedCase = (Case*)arrayCase[x][y];
}
