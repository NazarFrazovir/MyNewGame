//
// Created by Nazar Frazovir on 29.02.2024.
//

#include <iostream>
#include "SwordMan.h"
#include "Spell.h"

Spell::Spell()
:spell_for_damage(0),spell_for_mobility(0),spell_for_precision(0){}
Spell::Spell(int spell_for_damage, int spell_for_mobility, int spell_for_precision)
:spell_for_damage(spell_for_damage),spell_for_mobility(spell_for_mobility),spell_for_precision(spell_for_precision){}

int Spell::getDamageBonus() const {
    return spell_for_damage;
}
int Spell::getMobilityBonus() const {
    return spell_for_mobility;
}
int Spell::getPrecisionBonus() const {
    return spell_for_precision;
}

