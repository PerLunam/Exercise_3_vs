#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <ostream>
#include <string>

#include "item.h"
#include "type.h"

#define MAX_INVENTORY_SIZE 10

class Character
{
    private:
    std::string char_name;
    int char_health;
    int char_gold;
    int char_armor;
    int char_mr;
    Item inventory[MAX_INVENTORY_SIZE];

    protected:

    public:
    //Konstruktoren der Class "Character"
    //Default
    Character() : char_name("Default-Character")
    {
        std::cout << "Konstruktor: " << char_name << std::endl;
    }

    //Individueller Konstruktor
    Character(const std::string &name, int health, int gold, int armor, int mr)
        : char_name(name), char_gold(gold), char_armor(armor), char_mr(mr)
        {
            std::cout << "Konstruktor: " << char_name << std::endl;
        }
    
    //Destruktor
    virtual ~Character()
    {
        std::cout << "Destruktor: " << char_name << std::endl;
    }

    //----------------------------- Objektfunktionen -----------------------------
    virtual void attack(Character *enemy) = 0;

    bool fight(Character *enemy);

    int addInventarItem(Item &item);
    Item removeInventarItem(int slot);

    virtual enumType &getType() = 0;

    Item retrieveRandomLoot(Character *enemy);

    //----------------------------- Getter & Setter -----------------------------
    const std::string& getName() const;
    void setName(const std::string& newName);

    int getHealth() const;
    void setHealth(int newHealth);

    int getGold() const;
    void setGold(int newGold);

    int getArmor() const;
    void setArmor(int newArmor);

    int getMR() const;
    void setMR(int newMR);

    Item *getInventory(int index);
};

//Operatorenüberladung des Opterators "<<"
std::ostream& operator<<(std::ostream& out, const Character& c);

#endif //CHARACTER_H