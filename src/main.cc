#include <ctime>
#include <iostream>
#include "mobile.h"
 
int main()
{
    PlayerCharacter player;
    player.SetName("Omerye");
    Combatant cPlayer(player);

    Monster monster1;
    monster1.SetName("Giant Rat");

    /*Minion minion1;
    minion1.SetName("Skeleton");
    Minion minion2;
    minion2.SetName("Zombie");
    Minion minion3;
    minion3.SetName("Wraith");

    Monster monster1;
    monster1.SetName("Giant Rat");
    Monster monster2;
    monster2.SetName("Azure Slime");
    Monster monster3;
    monster3.SetName("Rat King");
    */

    cPlayer.Attack(monster1);
    cPlayer.combatant.Dodge();

    /*Character player;
    player.setName("Omerye");
    std::cout << ThisTime().Get();
    std::cout << "Your skeleton warrior hits " << ANSIColour().Colour("a yellow slime", YELLOW) << " for " << ANSIColour().Colour("15", RED) << " damage\n";
    std::cout << "Welcome to " << ANSIColour().Colour("Cellar Door", MAGENTA) << ", " << ANSIColour().Colour(player.GetName(), YELLOW) << "\n";
    */

    return 1;
}