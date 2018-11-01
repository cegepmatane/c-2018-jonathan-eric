#include "pch.h"
#include "Case.h"


Case::Case(float posX, float posY)
{
	m_PosX = posX;
	m_PosY = posY;
	characterOnCase = 0;

	vector<string> listPathRessource = {"..\\Ressource\\flower.jpg" , 
		"..\\Ressource\\grass.jpg",
		"..\\Ressource\\grass2.jpg",
		"..\\Ressource\\rock.jpg",
		"..\\Ressource\\grass.jpg",
		"..\\Ressource\\grass2.jpg",
		"..\\Ressource\\grass.jpg",
		"..\\Ressource\\grass2.jpg"};



	//cout << rand() % (listPathRessource.size()) << endl;


	string path = listPathRessource[rand() % (listPathRessource.size())];

	//string path = "..\\Ressource\\grass2.jpg";

	
	sprite = NULL;
	if (textureCase.loadFromFile(path))
	{
		sprite = new sf::Sprite(textureCase);
		sprite->setPosition(posX * WIDTH, posY * HEIGHT);
	}

}


Case::~Case()
{
	delete sprite;
}

void Case::changeCharacter(Character *a_character)
{
	this->characterOnCase = a_character;
}

void Case::removeCharacterOnCase()
{
	characterOnCase = 0;
}

void Case::displayConsol()
{
	cout << "[";
	if (isSelected)
		cout << ">";
	else
		cout << " ";

	if (characterOnCase != 0)
	{
		characterOnCase->displayConsol();
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

sf::Sprite* Case::getTexture()
{
	return sprite;
}

void Case::display(sf::RenderWindow* window)
{
	window->draw(*sprite);
	if (hasCharacter())
	{
		//characterOnCase->displayConsol();
		//cout << " : " << characterOnCase->getPathSprite() << endl;
		//characterOnCase->changePositionSprite(m_PosX * WIDTH, m_PosY * HEIGHT);
		//window->draw(*(characterOnCase->getSprite()));
		characterOnCase->display(m_PosX * WIDTH, m_PosY * HEIGHT, window);
	}
}
