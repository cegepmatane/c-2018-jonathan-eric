//============================================================================
// Name        : c-2018-jonathan-eric.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;
#include "Character/Character.h"
#include "Character/Barbarian.h"
#include "Character/Mage.h"
#include "Character/Archer.h"
#include "spell/Spell.h"
#include "spell/DancingLight.h"
#include "spell/smash.h"
#include <vector>


int main() {

	Spell *spell = new Spell("Spell", 50);
	Spell *dancingLight = new DancingLight();
	Spell *smash = new Smash();


	vector<Character*> listCharacter;



	//import init

	ifstream sourcePersonnages;
	sourcePersonnages.open("data/Personnages.csv");
	string ligne;

	int indexPersonnage = 0;
	bool firstLine = true;
	while(!sourcePersonnages.eof())
	{
		if (firstLine)
		{
			getline(sourcePersonnages, ligne);
			firstLine = false;
		}

		else
		{
			getline(sourcePersonnages,ligne);

			unsigned int positionDebut = 0;
			unsigned int positionFin = 0; //unsigned int fait en sorte que -1 donne la valeur maximum d'un int
			int indexColum = 0;

			do{
				positionFin = ligne.find(";", positionDebut);


				string value = ligne.substr(positionDebut,positionFin - positionDebut);
				cout << value << endl;

				switch(indexColum){

				case 0:

					if (value == "Barbarian")
					{
						listCharacter.push_back(new Barbarian());
					} else if (value == "Mage"){
						listCharacter.push_back(new Mage());
					} else if (value == "Archer"){
						listCharacter.push_back(new Archer());
					}


					break;

				case 1:
					listCharacter[indexPersonnage]->setName(value);
					break;

				case 2:
					listCharacter[indexPersonnage]->setHp(strtof((value).c_str(),0));
					break;

				case 3:
					listCharacter[indexPersonnage]->setDamageBasicAttaque(strtof((value).c_str(),0));
					break;

				case 4:

					if (value == "Smash")
					{
						listCharacter[indexPersonnage]->addSpell(smash);
					}
					else if (value == "DancingLight")
					{
						listCharacter[indexPersonnage]->addSpell(dancingLight);
					}

					break;

				default:

					break;

				}

				positionDebut = positionFin + 1;
				indexColum++;
			}while(positionDebut != 0);

			indexPersonnage++;
		}// fin boucle ligne

	}//fin lecture document


	//fin import init





	//creation donne test

	Character *barbarian = new Barbarian();
	barbarian->setHp(18);
	barbarian->setName("Theo");

	Character *mage = new Mage();
	mage->setHp(10);
	mage->setName("Bob");
	mage->addSpell(dancingLight);
	mage->addSpell(spell);

	//fin creation donne test


	//exportation fichier

	string const nomFichier("data/export.xml");
	ofstream monFlux(nomFichier.c_str());

	if(monFlux)
	{
		monFlux << barbarian->exporter() << endl;
		monFlux << mage->exporter() << endl;

		for (unsigned int i = 0; i < listCharacter.size() ; i++)
		{
			monFlux << listCharacter[i]->exporter() << endl;
		}
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
	}

	//fin exportation


	delete barbarian;
	delete mage;

	delete spell;
	delete dancingLight;

	return 0;
}
