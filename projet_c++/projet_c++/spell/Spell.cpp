/*
 * Spell.cpp
 *
 *  Created on: 26 sept. 2018
 *      Author: 1433081
 */
#include "pch.h"
#include "Spell.h"
#include "sstream"


Spell::Spell() {
	typeOfSpell = spelltype::damage;
}

Spell::~Spell() {

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

string Spell::exporter(string tabulation)
{
    stringstream xml;
    xml << tabulation + "<Spell>" << endl;
    xml << tabulation + "\t<name>" << m_Name << "</name>" << endl;
    xml << tabulation + "\t<damage>" << m_Damage <<"</damage>" << endl;

    xml << tabulation + "</Spell>" << endl;
    return xml.str();
}

Spell::spelltype Spell::getTypeOfSpell()
{
	return typeOfSpell;
}
