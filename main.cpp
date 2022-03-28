#include <iostream>
#include <cstdlib>
#include <ctime>

#include "character.h"
#include "hero.h"
//#include "npc.h"
#include "fighter.h"
#include "sorcerer.h"

int main()
{
    std::srand(time(nullptr));

    //Initialize Hero Annina und vier Items
    Hero annina("Annina", 700, 200, 15, 10);
    annina.addInventarItem(Item("Riesenschwert", 70));
    annina.addInventarItem(Item("Diamantamulett", 90));
    annina.addEquipmentItem(Item("Rosenlanze", 300));
    annina.addEquipmentItem(Item("Trank der Stärke", 25));

    //Grafische Trennung der Inhalte
    std::cout << "------------------------------" << std::endl;

    //Initialize Fighter matthias
    Fighter matthias("Matthias", 50, 100, 10, 5, 25);
    matthias.addInventarItem(Item("Bernsteinumhang", 250));
    matthias.addInventarItem(Item("Silberaxt", 170));
    matthias.addInventarItem(Item("Ahornstab", 150));

    //Grafische Trennung der Inhalte
    std::cout << "------------------------------" << std::endl;

    //Initialize Sorcerer pascal
    Sorcerer pascal("Pascal", 100, 300, 5, 10, 25);
    pascal.addInventarItem(Item("Zaubertrunk", 50));
    pascal.addInventarItem(Item("Nachtschattenrüstung", 350));
    pascal.addInventarItem(Item("Drachendolch", 100));

    //Grafische Trennung der Inhalte
    std::cout << "------------------------------" << std::endl;

    //Ansatz mit einer nested if-Loop
    if(annina.fight(&matthias))
    {
        annina.retrieveRandomLoot(&matthias);

        if(annina.fight(&pascal))
        {
            annina.retrieveRandomLoot(&pascal);

            //Erster Ansatz - Verwendung der "sellItem"-Funktion innerhalb einer nested Loop
            for(int i = 0; i < MAX_INVENTORY_SIZE; ++i)
            {
                for (int j = 0; j < MAX_EQUIPMENT_SIZE; ++j)
                {
                    annina.sellItem(j);
                }
                annina.sellItem(i);
            }
        }
    } else
    {
        //Falls die Heldin verliert...
        std::cout << annina.getName() << " fiel in Ohnmacht!" << std::endl;
        return 0;
    }

    return 0;
}