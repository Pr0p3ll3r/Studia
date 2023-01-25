#include "character.h"

Character::Character(std::string charClass, int hp, int mana, int level)
{
    this->charClass = charClass;
    this->hp = hp;
    this->mana = mana;
    this->level = level;
}

int Character::getHp() const
{
    return hp;
}

int Character::getMana() const
{
    return mana;
}

int Character::getLevel() const
{
    return level;
}

const std::string &Character::getCharClass() const
{
    return charClass;
}
