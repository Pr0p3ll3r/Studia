#include <iostream>
#include <vector>

using namespace std;

class City;
class Voivodeship;

class Citizen
{
friend class City;
friend class Voivodeship;
private:
    string name;
    string surname;
    int age;
    char sex;
    string postal_code;
public:
    Citizen()
    {

    }
    Citizen(string name, string surname, int age, char sex, string postal_code)
    {
        this->name=name;
        this->surname=surname;
        this->age=age;
        this->sex=sex;
        this->postal_code=postal_code;
    }
    void show()
    {
        cout<<name<<" "<<surname<<endl;
        cout<<"Wiek: "<<age<<" Plec: "<<sex<<endl;
        cout<<"Kod pocztowy: "<<postal_code<<endl;
    }
};

class City
{
friend class Voivodeship;
private:
    vector<Citizen> citizens;
    string city_name;
public:
    City()
    {

    }
    City(string city_name)
    {
        this->city_name=city_name;
    }
    void addCitizen(Citizen m)
    {
        citizens.push_back(m);
    }
    void deleteCitizen(string surname, int age)
    {
        for(int i=0; i<citizens.size(); i++)
        {
            if(citizens[i].surname == surname && citizens[i].age == age)
            {
                citizens.erase(citizens.begin()+i, citizens.begin()+i+1);
                break;
            }
        }
    }
    void show_citizens()
    {
        for(int i=0; i<citizens.size(); i++)
        {
            citizens[i].show();
            cout<<endl;
        }
    }
    void show_city()
    {
        cout<<"Nazwa miasta: "<<city_name<<endl;
    }
    int women()
    {
        int amount=0;
        for(int i=0; i<citizens.size(); i++)
        {
            if(citizens[i].name.back()=='a')
                amount++;
        }
        return amount;
    }
    int citizensAmount()
    {
        return citizens.size();
    }
    int adults()
    {
        int amount=0;
        for(int i=0; i<citizens.size(); i++)
        {
            if(citizens[i].age>=18)
                amount++;
        }
        return amount;
    }
};

class Voivodeship
{
private:
    string voivodeship_name;
    vector<City> cities;
public:
    Voivodeship(string voivodeship_name)
    {
        this->voivodeship_name=voivodeship_name;
    }
    void addCity(City m)
    {
        cities.push_back(m);
    }
    void deleteCity(string nazwa)
    {
        for(int i=0; i>cities.size(); i++)
        {
            if(cities[i].city_name == nazwa && cities[i].citizensAmount() == 0)
                cities.erase(cities.begin()+i, cities.begin()+i+1);
        }
    }
    void show_voivodeship()
    {
        cout<<"Wojewodztwo: "<<voivodeship_name<<endl;
        cout<<"Miasta: "<<endl;
        for(int i=0; i<cities.size(); i++)
        {
            cities[i].show_city();
        }
    }
    int citizens()
    {
        int amount=0;
        for(int i=0; i<cities.size(); i++)
        {
            for(int j=0; j<cities[i].citizens.size(); j++)
            {
                amount++;
            }
        }
        return amount;
    }
    int men()
    {
        int amount=0;
        for(int i=0; i<cities.size(); i++)
        {
            for(int j=0; j<cities[i].citizens.size(); j++)
            {
                if(cities[i].citizens[j].name.back()!='a')
                    amount++;
            }
        }
        return amount;
    }
    int children()
    {
        int amount=0;
        for(int i=0; i<cities.size(); i++)
        {
            for(int j=0; j<cities[i].citizens.size(); j++)
            {
                if(cities[i].citizens[j].age<18)
                    amount++;
            }
        }
        return amount;
    }
    friend void biggestCity(vector<Voivodeship> w);
    friend void biggestVoivodeship(vector<Voivodeship> w);
};

void biggestCity(vector<Voivodeship> w)
{
    int amount=0;
    City c;
    for(int i=0; i<w.size(); i++)
    {
        for(int j=0; j<w[i].cities.size(); j++)
        {
            if(w[i].cities[j].citizensAmount() > amount)
            {
                amount = w[i].cities[j].citizensAmount();
                c = w[i].cities[j];
            }
        }
    }
    c.show_city();
}

void biggestVoivodeship(vector<Voivodeship> w)
{
    int amount=0;
    int m=0;
    for(int i=0; i<w.size(); i++)
    {
        for(int j=0; j<w[i].cities.size(); j++)
        {
            if(w[i].cities[j].citizensAmount() > amount)
            {
                amount = w[i].cities[j].citizensAmount();
                m=i;
            }
        }
    }
    w[m].show_voivodeship();
}

int main()
{
    City c("Lublin");
    City c2("Warszawa");
    c.show_city();
    Citizen ci("Jakub", "Dudek", 21, 'M', "5232626");
    c.addCitizen(ci);
    c.show_citizens();
    vector<Voivodeship> w;
    Voivodeship wo("lubelskie");
    wo.addCity(c);
    wo.addCity(c2);
    w.push_back(wo);
    w[0].show_voivodeship();

    biggestCity(w);
    biggestVoivodeship(w);
    return 0;
}
