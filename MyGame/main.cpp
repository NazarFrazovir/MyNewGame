#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Game.h"
#include "SwordMan.h"
#include "Spell.h"

int main() {
    SwordMan Swordman1(10,100,100);
    Spell spell1(10,10,10);
    Swordman1.useSpell(spell1);         // Використання зілля
    Swordman1.setName("Nazar");
    Swordman1.setHealth(100);
    Swordman1.stat();

    return 0;
}
