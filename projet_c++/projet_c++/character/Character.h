/*
 * Character.h
 *
 *  Created on: 26 sept. 2018
 *      Author: 1433081
 */

#ifndef CHARACTER_CHARACTER_H_
#define CHARACTER_CHARACTER_H_
#include "../spell/Spell.h"
#include <vector>

#include <iostream>
using namespace std;

class Character {
public:
	Character();
	virtual ~Character();
	virtual void receiveDamage(float damage);
	virtual void attackTarget(Character &target);
	virtual void launchSpellAtTarget(Character &target, Spell &spell);
	virtual Spell& findSpell(std::string name);
	virtual void display();
	virtual string exporter();

	virtual float getDamageBasicAttaque() const;
	virtual void setDamageBasicAttaque(float damageBasicAttaque);
	virtual float getHp();
	virtual void setHp(float a_HP);
	virtual const std::string getName();
	virtual void setName(std::string a_name);
	virtual const vector<Spell*>& getSpellListe() const;
	virtual void setSpellListe(const vector<Spell*>& a_spellListe);
	virtual void addSpell(Spell *a_spell);
	virtual int getX();
	virtual int getY();
	virtual void setX(float a_X);
	virtual void setY(float a_Y);



protected:
	float m_HP;
	std::string m_Name;
	float m_damageBasicAttaque;
	vector<Spell*> m_SpellListe;
	std::string m_Class;
	int positionX;
	int positionY;
	
	
};

#endif /* CHARACTER_CHARACTER_H_ */
