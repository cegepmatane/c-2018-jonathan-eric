/*
 * Character.cpp
 *
 *  Created on: 26 sept. 2018
 *      Author: 1433081
 */

#include "Character.h"

Character::Character() {
	// TODO Auto-generated constructor stub

}

Character::~Character() {
	// TODO Auto-generated destructor stub
}
void Character::create(float a_HP){
	m_HP = a_HP;
	//Character::m_Name*& = a_name;
}


float Character::getHp() {
	return m_HP;
}

void Character::setHp(float a_HP) {
	m_HP = a_HP;
}

const std::string Character::getName() {
	return m_Name;
}

void Character::setName(std::string a_name) {
	m_Name = a_name;
}

const list<Spell*>& Character::getSpellListe() const {
	return m_SpellListe;
}

void Character::setSpellListe(const list<Spell*>& a_spellListe) {
	this->m_SpellListe = a_spellListe;
}
