//
// Created by Nazar Frazovir on 29.02.2024.
//
#include <iostream>
#include "Player.h"
#include "SwordMan.h"
#include "Spell.h"


SwordMan::SwordMan() :Player(){
    sword_Type[0] = "Basic";
    sword_damage= 10 ;
    precision = 5;
    mobility = 5;
}
SwordMan::SwordMan(int new_sword_damage, int new_precision,int new_mobility)
: Player("Unknown",0,0,0), sword_damage(new_sword_damage),
precision(new_precision),mobility(new_mobility){}

SwordMan &SwordMan::operator=(const SwordMan &other) {
    if(this != &other){
        Player::operator=(other);
        sword_damage = other.sword_damage;
    }
    return *this;
}

SwordMan::~SwordMan() {}

void SwordMan::useSpell(const Spell& spell) {
    precision += spell.getPrecisionBonus();
    sword_damage += spell.getDamageBonus();
    mobility += spell.getMobilityBonus();
}

void SwordMan::setSwordDamage(int new_sword_damage) {sword_damage=new_sword_damage;}
void SwordMan::setMobility(int new_mobility) {mobility=new_mobility;}
void SwordMan::setPrecision(int new_precision) {precision=new_precision;}
