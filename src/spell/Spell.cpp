/*
 * Spell.cpp
 *
 *  Created on: 26 sept. 2018
 *      Author: 1433081
 */

#include "Spell.h"

Spell::Spell() {
	// TODO Auto-generated constructor stub

}

Spell::~Spell() {
	// TODO Auto-generated destructor stub
}

Spell::Spell(std::string a_Name,float a_Damage)
{
	m_Name = a_Name;
	m_Damage = a_Damage;
}

float Spell::getDamage() const {
	return m_Damage;
}

void Spell::setDamage(float damage) {
	m_Damage = damage;
}

const std::string& Spell::getName() const {
	return m_Name;
}

void Spell::setName(const std::string& name) {
	m_Name = name;
}
