/*
 * Character.h
 *
 *  Created on: 26 sept. 2018
 *      Author: 1433081
 */

#ifndef CHARACTER_CHARACTER_H_
#define CHARACTER_CHARACTER_H_
#include "../spell/Spell.h"
#include <list>

#include <iostream>
using namespace std;

class Character {
public:
	Character();
	~Character();
	virtual void create(float a_HP);
	virtual float getHp();
	virtual void setHp(float a_HP);
	virtual const std::string getName();
	virtual void setName(std::string a_name);
	virtual const list<Spell*>& getSpellListe() const;
	virtual void setSpellListe(const list<Spell*>& a_spellListe);

protected:
	float m_HP;
	std::string m_Name;
	list<Spell*> m_SpellListe;
	
	
};

#endif /* CHARACTER_CHARACTER_H_ */
