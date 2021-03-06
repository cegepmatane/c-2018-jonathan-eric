/*
 * Spell.h
 *
 *  Created on: 26 sept. 2018
 *      Author: 1433081
 */

#ifndef SPELL_H_
#define SPELL_H_
#include<string>
using namespace std;


class Spell {
public:
	Spell();
	Spell(std::string a_Name,float a_Damage);
	virtual ~Spell();
	float getDamage() const;
	void setDamage(float damage);
	const std::string& getName() const;
	void setName(const std::string& name);
	virtual string exporter(string);

	enum spelltype {damage = 1, soulEating = 2};
	spelltype getTypeOfSpell();

protected:
	std::string m_Name;
	float m_Damage;
	spelltype typeOfSpell;
};

#endif /* SPELL_H_ */
