#include <iostream>

using namespace std;

class Animal
{
private:
    int limbNr;
    string name;
    bool isProtected;
public:
    Animal(int limbNr, string name)
    {
        this->limbNr=limbNr;
        this->name=name;
        this->isProtected=false;
        cout<<"Konstruktor parametrowy klasy Animal"<<endl;
    }
    Animal()
    {
        cout<<"Konstruktor bezparametrowy klasy Animal"<<endl;
    }
    void setProtected(bool prot)
    {
        isProtected=prot;
    }
    void setName(string name)
    {
        this->name=name;
    }
    void setLimbNr(int limbNr)
    {
        this->limbNr=limbNr;
    }
    bool getProtected()
    {
        return isProtected;
    }
    string getName()
    {
        return name;
    }
    int getLimbNr()
    {
        return limbNr;
    }
    void giveVoice()
    {
        cout<<"Chrum, miau, hau, piiiii"<<endl;
    }
    void info()
    {
        cout<<"Imie: "<<name<<" Liczba konczyn: "<<limbNr<<" Chroniony: "<<isProtected<<endl;
    }
};

class Dog : public Animal
{
private:
    string breed;
    int levelOfGuideSkills;
    int levelOfTrackerSkills;
public:
    Dog(int limbNr, string name, string breed, int levelOfGuideSkills, int levelOfTrackerSkills):Animal(limbNr, name)
    {
        this->breed=breed;
        this->levelOfGuideSkills=levelOfGuideSkills;
        this->levelOfTrackerSkills=levelOfTrackerSkills;
        cout<<"Konstruktor parametrowy klasy pochodnej Dog"<<endl;
    }
    void setSkillLevel(int type, int level)
    {
        if(type==0)
        {
            levelOfGuideSkills=level;
        }
        else if(type==1)
        {
            levelOfTrackerSkills=level;
        }
    }
    int getSkillLevel(int type)
    {
        if(type==0)
        {
            if(levelOfGuideSkills == NULL)
                return 0;

            return levelOfGuideSkills;
        }
        else if(type==1)
        {
            if(levelOfTrackerSkills == NULL)
                return 0;

            return levelOfTrackerSkills;
        }
    }
    void giveVoice()
    {
        cout<<"Hau, hau"<<endl;
    }
    void info()
    {
        Animal::info();
        cout<<"Rasa: "<<breed<<" Poziom umiejetnosci przewodnika: "<<levelOfGuideSkills<<" Poziom umiejetnosci tropiciela: "<<levelOfTrackerSkills<<endl;
    }
};

int main()
{
    Animal a(4, "Kajtek");
    a.info();
    a.setProtected(true);
    a.info();

    Dog d(4, "Miko", "Sznaucer", 5, 5);
    d.info();
    d.giveVoice();
    return 0;
}
