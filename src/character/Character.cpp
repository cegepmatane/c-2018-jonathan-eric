/*
 * Character.cpp
 *
 *  Created on: 26 sept. 2018
 *      Author: 1433081
 */

#include "Character.h"
#include "sstream"

Character::Character() {
	// TODO Auto-generated constructor stub

	m_Class = "Character";
	m_damageBasicAttaque = 10;
}

Character::~Character() {
	// TODO Auto-generated destructor stub
}

void Character::receiveDamage(float damage)
{
	m_HP -= damage;
}

void Character::attackTarget(Character &target)
{
	target.receiveDamage(m_damageBasicAttaque);
}

string Character::exporter()
{
    stringstream xml;
    xml << "<Character>" << endl;
    xml << "\t<class>" << m_Class << "</class>" << endl;
    xml << "\t<name>" << m_Name << "</name>" << endl;
    xml << "\t<HP>" << m_HP <<"</HP>" << endl;
    xml << "\t<damageBasicAttaque>" << m_damageBasicAttaque <<"</damageBasicAttaque>" << endl;
    xml << "\t<listSpell>" << endl;
    for (unsigned int i = 0; i < m_SpellListe.size() ; i++)
    {
    	xml << m_SpellListe[i]->exporter("\t");
    }
    xml << "\t</listSpell>" << endl;
    xml << "</Character>" << endl;
    return xml.str();
}



float Character::getDamageBasicAttaque() const {
	return m_damageBasicAttaque;
}

void Character::setDamageBasicAttaque(float damageBasicAttaque) {
	m_damageBasicAttaque = damageBasicAttaque;
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

const vector<Spell*>& Character::getSpellListe() const {
	return m_SpellListe;
}

void Character::setSpellListe(const vector<Spell*>& a_spellListe) {
	this->m_SpellListe = a_spellListe;
}

void Character::addSpell(Spell *a_spell)
{
	this->m_SpellListe.push_back(a_spell);
}
