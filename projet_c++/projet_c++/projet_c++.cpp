// projet_c++.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include <iostream>
#include <fstream>
#include "Character/Character.h"
#include "Character/Barbarian.h"
#include "Character/Mage.h"
#include "Character/Archer.h"
#include "spell/Spell.h"
#include "spell/DancingLight.h"
#include "spell/smash.h"
#include "spell/SoulEater.h"
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include "conio.h"
#include "Grille.h"
#include <SFML/Graphics.hpp>
using namespace std;

void displayControl();

int main() {

	enum keyConfiguration : int {
		exit = sf::Keyboard::Escape /*esc*/, changeSelection = sf::Keyboard::Tab/*tab*/,
		moveRight = sf::Keyboard::D, moveUp = sf::Keyboard::W, moveDown = sf::Keyboard::S, moveLeft = sf::Keyboard::A,
		toggleAttack = sf::Keyboard::E, confirm = sf::Keyboard::Space /*space bar*/,
		spell1 = sf::Keyboard::Num1, spell2 = sf::Keyboard::Num2, spell3 = sf::Keyboard::Num3
	};

	enum lockConfiguration { character = 1, attack = 2};



	/*while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}*/

	vector<Character*> listCharacter;

#pragma region import

	//import init

	ifstream sourcePersonnages;
	sourcePersonnages.open("../data/Personnages.csv");
	string ligne;

	int indexPersonnage = 0;
	bool firstLine = true;
	while (!sourcePersonnages.eof())
	{
		if (firstLine)
		{
			getline(sourcePersonnages, ligne);
			firstLine = false;

		}

		else
		{
			getline(sourcePersonnages, ligne);

			unsigned int positionDebut = 0;
			unsigned int positionFin = 0; //unsigned int fait en sorte que -1 donne la valeur maximum d'un int
			int indexColum = 0;

			do {
				positionFin = ligne.find(";", positionDebut);


				string value = ligne.substr(positionDebut, positionFin - positionDebut);
				//cout << value << endl;

				switch (indexColum) {

				case 0:

					if (value == "Barbarian")
					{
						listCharacter.push_back(new Barbarian());
					}
					else if (value == "Mage") {
						listCharacter.push_back(new Mage());
					}
					else if (value == "Archer") {
						listCharacter.push_back(new Archer());
					}


					break;

				case 1:
					listCharacter[indexPersonnage]->setName(value);
					break;

				case 2:
					listCharacter[indexPersonnage]->setHp(strtof((value).c_str(), 0));
					break;

				case 3:
					listCharacter[indexPersonnage]->setDamageBasicAttaque(strtof((value).c_str(), 0));
					break;

				case 4:

					if (value == "Smash")
					{
						listCharacter[indexPersonnage]->addSpell(new Smash());
					}
					else if (value == "DancingLight")
					{
						listCharacter[indexPersonnage]->addSpell(new DancingLight());
					}
					else if (value == "SoulEater")
					{
						listCharacter[indexPersonnage]->addSpell(new SoulEater());
					}

					break;

				case 5:
					listCharacter[indexPersonnage]->setVertical((strtof((value).c_str(), 0)));

					break;

				case 6:

					listCharacter[indexPersonnage]->setHorizontal((strtof((value).c_str(), 0)));

					break;

				default:

					break;

				}

				positionDebut = positionFin + 1;
				indexColum++;
			} while (positionDebut != 0);

			indexPersonnage++;
		}// fin boucle ligne


	}//fin lecture document


	//fin import init

#pragma endregion

	/*
#pragma region testInteraction



	//creation donne test
	Spell *spell = new Spell("Spell", 50);
	Spell *dancingLight = new DancingLight();
	Spell *smash = new Smash();


	Character *barbarian = new Barbarian();
	barbarian->setHp(100);
	barbarian->setName("Theo");

	Character *mage = new Mage();
	mage->setHp(50);
	mage->setName("Bob");
	mage->addSpell(dancingLight);
	mage->addSpell(spell);

	//fin creation donne test


	//test interaction
	std::cout << barbarian->exporter() << endl;
	std::cout << mage->exporter() << endl;

	std::cout << "barbarian attack mage for " << barbarian->getDamageBasicAttaque() << endl;
	barbarian->attackTarget(*mage);
	std::cout << mage->exporter() << endl;

	std::cout << "mage launch spell Dancing light to barbarian for " << mage->findSpell(dancingLight->getName()).getDamage() << endl;

	mage->launchSpellAtTarget(*barbarian, mage->findSpell(dancingLight->getName()));
	std::cout << barbarian->exporter() << endl;
	//fin test interaction

#pragma endregion
*/


#pragma region gameLoop

	//debut boucle de jeu
	sf::RenderWindow window(sf::VideoMode(Grille::configMap::mapWidth * 32, Grille::configMap::mapHeight * 32), "SFML works!");

	int frame = 0;
	int key;
	bool gameIsRunning = true;
	Grille *grille = new Grille();
	int selectedCharacter = 0;
	std::string error;
	int selectionType;
	Spell *spellToLaunch(0);

	
	for (unsigned int indexCharacter = 0; indexCharacter < listCharacter.size(); indexCharacter++)
	{
		grille->setCharacterAt(listCharacter[indexCharacter], listCharacter[indexCharacter]->getVertical(), listCharacter[indexCharacter]->getHorizontal());
	}



	
	while (window.isOpen())
	{
		if (frame == 0)
		{
			//system("cls");

			selectionType = lockConfiguration::character;
			if (listCharacter.size() > selectedCharacter)
			{

				grille->selecteCase(listCharacter[selectedCharacter]->getHorizontal(), listCharacter[selectedCharacter]->getVertical(), Case::TYPE_OF_SELECT::caseSelect);

				listCharacter[selectedCharacter]->displayStatistique();
			}
			grille->displayConsol(listCharacter);
			grille->loadSpriteAllCharacter();

			displayControl();
		}


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			//system("cls");


			// lire les entrées sans bloquer la boucle
			if (event.type == sf::Event::KeyPressed)
			{
				system("cls");

				error = "";

				key = event.key.code;
				//cout << "key " << key << " " << frame << endl;
				if (key == keyConfiguration::exit)
				{
					gameIsRunning = false;
					window.close();
				}

				//region for control of Character
#pragma region CharacterControlKey
				if (selectionType == lockConfiguration::character)
				{
					switch (key)
					{

					case keyConfiguration::changeSelection:
						selectedCharacter++;
						if (selectedCharacter >= listCharacter.size())
							selectedCharacter = 0;

						grille->selecteCase(listCharacter[selectedCharacter]->getVertical(), listCharacter[selectedCharacter]->getHorizontal(), Case::TYPE_OF_SELECT::caseSelect);

						break;

					case keyConfiguration::moveRight:

						if (listCharacter[selectedCharacter]->getHorizontal() + 1 >= Grille::configMap::mapWidth)
							error = "path block";

						else
							listCharacter[selectedCharacter]->moveRight();

						break;

					case keyConfiguration::moveLeft:
						if (listCharacter[selectedCharacter]->getHorizontal() - 1 < 0)
							error = "path block";
						else
							listCharacter[selectedCharacter]->moveLeft();

						break;

					case keyConfiguration::moveUp:
						if (listCharacter[selectedCharacter]->getVertical() - 1 < 0)
							error = "path block";
						else
							listCharacter[selectedCharacter]->moveUp();

						break;

					case keyConfiguration::moveDown:
						if (listCharacter[selectedCharacter]->getVertical() + 1 >= Grille::configMap::mapHeight)
							error = "path block";
						else
							listCharacter[selectedCharacter]->moveDown();
						break;

					case keyConfiguration::toggleAttack:
						selectionType = lockConfiguration::attack;

						break;

					case keyConfiguration::spell1:
						if (listCharacter[selectedCharacter]->getSpellListe().size() >= 1)
						{
							spellToLaunch = listCharacter[selectedCharacter]->getSpellListe()[0];
							selectionType = lockConfiguration::attack;
						}
						else
							error = "no spell";

						break;

					case keyConfiguration::spell2:
						if (listCharacter[selectedCharacter]->getSpellListe().size() >= 2)
						{
							spellToLaunch = listCharacter[selectedCharacter]->getSpellListe()[1];
							selectionType = lockConfiguration::attack;
						}
						else
							error = "no spell";

						break;

					case keyConfiguration::spell3:
						if (listCharacter[selectedCharacter]->getSpellListe().size() >= 3)
						{

							spellToLaunch = listCharacter[selectedCharacter]->getSpellListe()[2];
							selectionType = lockConfiguration::attack;
						}
						else
							error = "no spell";

						break;

					default:
						break;
					}
					//system("cls");
					std::cout << "character mode" << std::endl;
					grille->selecteCase(listCharacter[selectedCharacter]->getHorizontal(), listCharacter[selectedCharacter]->getVertical(), Case::TYPE_OF_SELECT::caseSelect);
					listCharacter[selectedCharacter]->displayStatistique();
					grille->displayConsol(listCharacter);
					std::cout << error << endl;

				}
#pragma endregion


#pragma region AttackControlKey

				else if (selectionType == lockConfiguration::attack)
				{
					switch (key)
					{

					case keyConfiguration::moveRight:

						if (grille->getSelectedHorizontal() + 1 >= Grille::configMap::mapWidth)
							error = "path block";

						else
							grille->moveSelectedCaseRight();

						break;

					case keyConfiguration::moveLeft:
						if (grille->getSelectedHorizontal() - 1 < 0)
							error = "path block";
						else
							grille->moveSelectedCaseLeft();

						break;

					case keyConfiguration::moveUp:
						if (grille->getSelectedVertical() - 1 < 0)
							error = "path block";
						else
							grille->moveSelectedCaseUp();

						break;

					case keyConfiguration::moveDown:
						if (grille->getSelectedVertical() + 1 >= Grille::configMap::mapHeight)
							error = "path block";
						else
							grille->moveSelectedCaseDown();

						break;

					case keyConfiguration::toggleAttack:
						selectionType = lockConfiguration::character;

						break;

					case keyConfiguration::confirm:
						if (grille->getselectedCase()->hasCharacter())
						{
							if (spellToLaunch != 0)
							{
								listCharacter[selectedCharacter]->launchSpellAtTarget(*grille->getselectedCase()->getCharacter(), *spellToLaunch);
								spellToLaunch = 0;
							}
							else
							{
								listCharacter[selectedCharacter]->attackTarget(*grille->getselectedCase()->getCharacter());
							}
							selectionType = lockConfiguration::character;
						}
						else
							error = "no target";

						break;

					default:
						break;
					}
					//system("cls");
					cout << "attack mode (press space to attack)" << endl;
					grille->selecteCase(grille->getSelectedHorizontal(), grille->getSelectedVertical(),Case::TYPE_OF_SELECT::caseTarget);
					listCharacter[selectedCharacter]->displayStatistique();
					grille->displayConsol(listCharacter);
					std::cout << error << endl;

				}
#pragma endregion


				displayControl();

			} //fin if key press
		}


		window.clear();


		grille->display(&window);


		window.display();

		frame++;
	}

	//fin boucle de jeu

#pragma endregion


#pragma region exportation

//exportation fichier

	string const nomFichier("../data/Export.xml");
	ofstream monFlux(nomFichier.c_str());

	if (monFlux)
	{
		//monFlux << barbarian->exporter() << endl;
		//monFlux << mage->exporter() << endl;

		for (unsigned int i = 0; i < listCharacter.size(); i++)
		{
			monFlux << listCharacter[i]->exporter() << endl;
		}
	}
	else
	{
		std::cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
	}

	//fin exportation

#pragma endregion



	//delete barbarian;
	//delete mage;

	for (unsigned int i = 0; i < listCharacter.size(); i++)
	{
		delete listCharacter[i];
	}
	
	//delete spell;
	//delete dancingLight;
	//delete smash;

	delete grille;

	return 0;
}

void displayControl()
{
	cout << "--------Control--------" << endl;
	cout << "w, a, s, d : move" << endl;
	cout << "e : basicAttaque" << endl;
	cout << "1, 2, 3 : spell" << endl;
	cout << "esc : exit" << endl;
	cout << "-----------------------" << endl;
}