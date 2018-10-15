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
#include "spell/Spell.h"
#include "spell/DancingLight.h"
#include "spell/smash.h"

int main() {

	Spell *spell = new Spell("Spell", 50);
	Spell *dancingLight = new DancingLight();
	Spell *smash = new Smash();


	vector<Character*> listeCharacter;





	//import init
	ifstream sourcePersonnages;
	sourcePersonnages.open("data/Personnages.csv");
	string ligne;

	int indexPersonnage = 0;
	while(!sourcePersonnages.eof())
	{

		getline(sourcePersonnages,ligne);

		unsigned int positionDebut = 0;
		unsigned int positionFin = 0; //unsigned int fait en sorte que -1 donne la valeur maximum d'un int
		int indexColum = 0;

		do{
			positionFin = ligne.find(";", positionDebut);


			string valeur = ligne.substr(positionDebut,positionFin - positionDebut);
			cout << valeur << endl;

			//cout << "position positionFin avant +1 : " << positionFin << endl;
			//cout << "position positionFin après +1 : " << positionFin + 1 << endl;

			switch(indexColum){

			case 0:

				switch(valeur){
				case "Barbarian":
						//do stuff
					break;
				}

				break;
			}

			positionDebut = positionFin + 1;
			indexColum++;
		}while(positionDebut != 0);

		/*
		cout << "La ligne est " << ligne << endl;
		int positionPremiereVirgule = ligne.find(";", 0);//0 = position de départ de la recherche
		cout << "Position de la premiere virgule " << positionPremiereVirgule << endl;
		string mot = ligne.substr(0,positionPremiereVirgule);
		cout << "Le premier mot découpé est " << mot << endl;
		*/

	}


	//fin import init






	Character *barbarian = new Barbarian();
	barbarian->setHp(18);
	barbarian->setName("Theo");
	//barbarian->getSpellListe().push_back()

	Character *mage = new Mage();
	mage->setHp(10);
	mage->setName("Bob");
	mage->addSpell(dancingLight);
	mage->addSpell(spell);

	for (unsigned int i = 0; i < mage->getSpellListe().size();i++)
	{
		cout << mage->getSpellListe()[i]->getName() << endl;
	}

	cout << barbarian->getHp() << endl;






	//exportation fichier

	string const nomFichier("data/export.xml");
	ofstream monFlux(nomFichier.c_str());

	if(monFlux)
	{
		monFlux << barbarian->exporter() << endl;
		monFlux << mage->exporter() << endl;
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
	}




	delete barbarian;
	delete mage;

	delete spell;
	delete dancingLight;

	return 0;
}
