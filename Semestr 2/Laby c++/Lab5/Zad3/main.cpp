#include <iostream>

using namespace std;

class Object
{
private:
    string serialNr;
    string title;
    bool borrowed;
public:
    Object(string serialNr, string title)
    {
        this->serialNr=serialNr;
        this->title=title;
        borrowed=0;
    }
    Object()
    {
        serialNr="";
        title="";
        borrowed=0;
    }
    void setSerialNr(string nr)
    {
        serialNr=nr;
    }
    void setTitle(string title)
    {
        this->title=title;
    }
    void setBorrowed(bool status)
    {
        borrowed=status;
    }
    void info()
    {
        cout<<"Numer seryjny: "<<serialNr<<" Tytul: "<<title<<" Wypozyczony? "<<borrowed<<endl;
    }
    bool isBorrowed()
    {
        if(borrowed==false)
            return false;
        else
            return true;
    }
};

class Book : public Object
{
private:
    string author;
    string description;
    int pageNr;
public:
    Book(string serialNr, string title, string author, string description, int pageNr):Object(serialNr, title)
    {
        this->author=author;
        this->description=description;
        this->pageNr=pageNr;
    }
    Book()
    {
        author="";
        description="";
        pageNr=0;
    }
    void setAuthor(string author)
    {
        this->author=author;
    }
    void setDescription(string description)
    {
        this->description=description;
    }
    void setPageNr(int pageNr)
    {
        this->pageNr=pageNr;
    }
    string getAuthor()
    {
        return author;
    }
    string getDescription()
    {
        return description;
    }
    int getPageNr()
    {
        return pageNr;
    }
    void info()
    {
        cout<<"Autor: "<<author<<" Opis: "<<description<<" Liczba stron: "<<pageNr<<endl;
    }
    void borrow()
    {
        setBorrowed(true);
    }
    void fullInfo()
    {
        Object::info();
        info();
    }
};

class Newspaper : public Object
{
private:
    string publishmentNr;
    int publishmentYear;
public:
    Newspaper(string serialNr, string title, string publishmentNr, int publishmentYear):Object(serialNr, title)
    {
        this->publishmentNr=publishmentNr;
        this->publishmentNr=publishmentNr;
    }
    Newspaper()
    {
        publishmentYear=0;
        publishmentNr="";
    }
    void setPublishmentNr(string nr)
    {
        publishmentNr=nr;
    }
    void setPublishmentYear(int year)
    {
        publishmentYear=year;
    }
    string getPublishmentNr()
    {
        return publishmentNr;
    }
    int getPublishmentYear()
    {
        return publishmentYear;
    }
    void info()
    {
        cout<<"Numer publikacji: "<<publishmentNr<<" Rok publikacji: "<<publishmentYear<<endl;
    }
    void borrow()
    {
        setBorrowed(true);
    }
    void fullInfo()
    {
         Object::info();
         info();
    }
    int howMuchOlder()
    {
        return 2021-getPublishmentYear();
    }
};

void minPage(Book books[], int n)
{
    int minimum=books[0].getPageNr();
    for(int i=1;i<n;i++)
    {
        if(books[i].getPageNr()<minimum)
        {
            minimum=books[i].getPageNr();
        }
    }
    for(int i=0;i<n;i++)
    {
        if(books[i].getPageNr()==minimum)
        {
            books[i].fullInfo();
        }
    }
}

int howManyBorrowed(Newspaper news[], int n)
{
    int ile=0;
    for(int i=0;i<n;i++)
    {
        if(news[i].isBorrowed()==true)
            ile++;
    }
    return ile;
}

int main()
{
    Book b("12345", "Wladca Pierscieni", "Tolkien", "Podroz hobbita i jego osmiu towarzyszy", 448);
    b.fullInfo();

    Book books[5];
    books[0].setPageNr(100);
    books[1].setPageNr(200);
    books[2].setPageNr(300);
    books[3].setPageNr(50);
    books[4].setPageNr(50);
    minPage(books, 5);

    Newspaper news[5];
    cout<<howManyBorrowed(news, 5)<<endl;
    news[0].setBorrowed(true);
    cout<<howManyBorrowed(news, 5)<<endl;
    return 0;
}
