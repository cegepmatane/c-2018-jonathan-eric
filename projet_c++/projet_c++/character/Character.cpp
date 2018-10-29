/*
 * Character.cpp
 *
 *  Created on: 26 sept. 2018
 *      Author: 1433081
 */
#include "pch.h"
#include "Character.h"
#include "sstream"

Character::Character() {
	// TODO Auto-generated constructor stub

	m_Class = "Character";
	m_damageBasicAttaque = 10;
}

Character::~Character() {
	// TODO Auto-generated destructor stub
	for (int i = 0; i < m_SpellListe.size(); i++)
	{
		delete m_SpellListe[i];
	 }
}

void Character::receiveDamage(float damage)
{
	m_HP -= damage;
}

void Character::attackTarget(Character &target)
{
	target.receiveDamage(m_damageBasicAttaque);
}

void Character::launchSpellAtTarget(Character &target, Spell &spell)
{
	switch (spell.getTypeOfSpell())
	{
	case Spell::spelltype::damage:
		target.receiveDamage(spell.getDamage());
		break;

	case Spell::spelltype::soulEating:
		*this = *this + target;
		break;

	default:
		break;
	}
}


Spell& Character::findSpell(std::string name)
{
	for (unsigned int i = 0; i < this->m_SpellListe.size() ; i++)
	{
		if (this->m_SpellListe[i]->getName() == name)
			return *m_SpellListe[i];
	}
	Spell *spell(0);
	return *spell;
}

void Character::displayConsol()
{
	cout << this->m_Name[0];
}

void Character::displayStatistique()
{
	cout << "nom: " << m_Name << endl;
	cout << "vie: " << m_HP << endl;
	cout << "damage: " << m_damageBasicAttaque << endl;

	for (int i = 0; i < m_SpellListe.size(); i++)
	{
		cout << "spell" << i + 1 << " : " << m_SpellListe[i]->getName() << " (" << m_SpellListe[i]->getDamage() << ")" << endl;
	}
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

int Character::getVertical()
{
	return positionVertical;
}

int Character::getHorizontal()
{
	return positionHorizontal;
}

void Character::setVertical(float a_X)
{
	positionVertical = a_X;
}

void Character::setHorizontal(float a_Y)
{
	positionHorizontal = a_Y;
}

void Character::moveDown()
{
	positionVertical++;
}

void Character::moveUp()
{
	positionVertical--;
}

Character Character::operator+(Character & a_character)
{
	Character character;
	character.m_HP = this->m_HP + a_character.getHp();
	character.m_damageBasicAttaque = this->m_damageBasicAttaque + a_character.getDamageBasicAttaque();
	character.m_Name = this->m_Name + " " + a_character.getName();
	character.positionHorizontal = this->getHorizontal();
	character.positionVertical = this->getVertical();
	character.m_Class = this->m_Class;

	//cout << character.m_HP << endl;
	return character;

}

void Character::moveRight()
{
	positionHorizontal++;
}

void Character::moveLeft()
{
	positionHorizontal--;
}
