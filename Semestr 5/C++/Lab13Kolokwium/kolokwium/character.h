#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>

class Character
{
private:
    std::string charClass;
    int hp;
    int mana;
    int level;
public:
    Character(std::string charClass, int hp, int mana, int level);
    const std::string &getCharClass() const;
    int getHp() const;
    int getMana() const;
    int getLevel() const;
};

#endif // CHARACTER_H
