//============================================================================
// Name        : c-2018-jonathan-eric.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Character/Character.h"
#include "Character/Barbarian.h"
#include "spell/Spell.h"
#include "spell/Fireball.h"

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	Spell *spell = new Spell("Spell", 50);
	cout << spell->getName() << endl;

	Spell *fireball = new Fireball("Fireball", 50);



	Character *barbarian = new Barbarian();
	barbarian->setHp(10);
	barbarian->setName("Bob");
	//barbarian->getSpellListe().push_back()

	cout << barbarian->getHp() << endl;


	return 0;
}
