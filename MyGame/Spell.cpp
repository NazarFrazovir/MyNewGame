//
// Created by Nazar Frazovir on 29.02.2024.
//

#include <iostream>
#include "SwordMan.h"
#include "Spell.h"

Spell::Spell()
:spell_for_damage(spell_for_damage > 0 ? spell_for_damage : 10){}
Spell::Spell(int spell_for_damage)
:spell_for_damage(spell_for_damage){}
Spell::~Spell() {}
int Spell::getDamageBonus()const {
    return spell_for_damage;
}


