#ifndef CAT_H
#define CAT_H

#include "animal.h"

class Cat : public Animal
{
private:
    int levelOfMouseHunting;
    int mice[5];
public:
    Cat();
    Cat(int limbNr1, std::string name1, bool protectedAnimal1 = true);
    void initMice(int values[]);
    void initCat(int levelOfMouseHunting1, int mice1[]);
    void setLevelOfMouseHunting(int value);
    int getLevelOfMouseHunting() const;
    int getMice(int index) const;
    void giveVoice();
    void info();
};

#endif // CAT_H
