/*
 * Fireball.h
 *
 *  Created on: 28 sept. 2018
 *      Author: 1433081
 */

#ifndef SPELL_FIREBALL_H_
#define SPELL_FIREBALL_H_
#include "Spell.h"

class Fireball : public Spell {
public:
	Fireball();
	virtual ~Fireball();

	Fireball() : Spell(a_Name, a_Damage)    // Call the superclass constructor in the subclass' initialization list.
	        {
	            // do something with bar
	        }
};

#endif /* SPELL_FIREBALL_H_ */
