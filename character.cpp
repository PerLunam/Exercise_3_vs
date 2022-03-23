#include "character.h"

#include <iostream>

//----------------------------- Objektfunktionen -----------------------------
bool Character::fight(Character *enemy)
{
    std::cout << enemy->getName() << " fordert " << this->getName() << " zu einem Kampf um Ruhm und Ehre heraus." << std::endl;
    
    if(this->getHealth() > 0 && enemy->getHealth() > 0)
    {
        this->attack(enemy);
        
        if(enemy->getHealth() > 0)
        {
            enemy->attack(this);
        }
    }
    return this->getHealth() > 0;
}

int Character::addInventarItem(Item &item)
{
    for(int i = 0; i < MAX_INVENTORY_SIZE; i++)
    {
        if(!this->inventory[i].isIsValid())
        {
            this->inventory[i].setName(item.getName());
            this->inventory[i].setValue(item.getValue());
            //this->inventory[i].isValid(true);
            this->inventory[i].setIsValid(item.isIsValid());

            //Bei erfolgreicher Platzierung soll der Index des Items ausgegeben werden
            return i;
        }
    }
    //Falls alle Plätze belegt sind oder der Platz falsch initialisiert ist, soll der Wert "-1" ausgegeben werden
    return -1;
}

Item Character::removeInventarItem(int slot)
{
    if(this->inventory[slot].isIsValid())
    {
        this->inventory[slot].setIsValid(false);
        std::cout << "Das Item " << this->inventory[slot].getName() << " wurde aus dem Invenatr von " << this->getName() << " entfernt." << std::endl;
        return this->inventory[slot];
    } else
    {
        //Falls alle Plätze belegt oder der Slot fehlerhaft initialisiert sein,
        //wird der Default-Konstruktor verwendet und das Item "Default-Item" mit isValid "false" ausgegeben
        return Item();
    }
}

Item Character::retrieveRandomLoot(Character *enemy)
{
    //Zufällige Zahl wird generiert und dient als Kriterium für die Auswahl des entsprechenden Item-Slots
    int rndNumber = rand() % (MAX_INVENTORY_SIZE + 1);

    if(this->inventory[rndNumber].isIsValid())
    {
        //TODO - Fehler beheben
        this->addInventarItem(enemy->removeInventarItem(rndNumber));
    }
}

//----------------------------- Getter & Setter -----------------------------
const std::string& Character::getName() const
{
    return this->char_name;
}

void Character::setName(const std::string& newName)
{
    this->char_name = newName;
}

int Character::getHealth() const
{
    return this->char_health;
}

void Character::setHealth(int newHealth)
{
    this->char_health = newHealth;
}

int Character::getGold() const
{
    return this->char_gold;
}

void Character::setGold(int newGold)
{
    this->char_gold = newGold;
}

int Character::getArmor() const
{
    return this->char_armor;
}

void Character::setArmor(int newArmor)
{
    this->char_armor = newArmor;
}

int Character::getMR() const
{
    return this->char_mr;
}

void Character::setMR(int newMR)
{
    this->char_mr = newMR;
}

Item *Character::getInventory(int index)
{
    Item &item = this->inventory[index];
    return &item;
}

//Operatorenüberladung des Opterators "<<"
std::ostream& operator<<(std::ostream& out, const Character& c)
{
    std::cout << c.getName() << " mit " << c.getHealth() << " Lebenspunkten, " << c.getArmor() << " Rüstungspunkte, " << c.getMR() << " Magieresistenz und " << c.getGold() << " Gold." << std::endl;
    return out;
}