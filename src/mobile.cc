#include "mobile.h"
#include <iostream>

void PlayerCharacter::Attack(Mobile &defender)
{
    std::cout << this->GetName() << " attacks " << defender.GetName() << " for 20 damage\n";
}

void PlayerCharacter::Dodge()
{
    std::cout << "You dodge!\n";
}

void Minion::Attack(Mobile &defender)
{
    std::cout << this->GetName() << " attacks " << defender.GetName() << " for 15 damage\n";
}

void Monster::Attack(Mobile &defender)
{
    std::cout << this->GetName() << " attacks " << defender.GetName() << " for 12 damage\n";
}

void Monster::Dodge()
{
    std::cout << this->name << " dodges your attack!\n";
}

void Combatant::Attack(Mobile &defender)
{
    std::cout << combatant.GetName() << " attacks " << defender.GetName() << " for 12 damage\n";
}