#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

void generate(string word, char list[], int size, int count, ofstream& file, int& counter)
{
    if (count==0)
    {
        cout<<word<<endl;
        counter++;
    }
    else
    {
        for (int i=0;i<size;i++)
        {
            generate(word + list[i], list, size, count-1, file, counter);
        }
    }
}

int main()
{
    int counter;
    clock_t start, end;
    ofstream file;
    double passed;
    char list[26] = {};
    char list2[52] = {};
    char list3[95] = {};
    int i=0;
    for(i;i<26;i++)
    {
        list[i]=i+97;
        list2[i]=i+97;
    }
    i=0;
    for(int j=26;j<52;j++)
    {
        list2[j]=i+65;
        i++;
    }
    for(int k=0;k<95;k++)
    {
        list3[k]=k+32;
    }


    cout<<"Male"<<endl;
    start = clock();
    file.open("trzy_male.txt");
    generate("", list, 26, 3, file, counter);
    file.close();
    end = clock();
    passed = double(end-start)/CLOCKS_PER_SEC;
    cout<<"3-"<<counter<<endl;
    cout<<"Czas: "<<passed<<"s"<<endl;
/*
    start = clock();
    file.open("cztery_male.txt");
    counter=0;
    generate("", list, 26, 4, file, counter);
    file.close();
    end = clock();
    passed =double(end-start)/CLOCKS_PER_SEC;
    cout<<"4-"<<counter<<endl;
    cout<<"Czas: "<<passed<<"s"<<endl;

    start = clock();
    file.open("piec_male.txt");
    counter=0;
    generate("", list, 26, 5, file, counter);
    file.close();
    end = clock();
    passed =double(end-start)/CLOCKS_PER_SEC;
    cout<<"5-"<<counter<<endl;
    cout<<"Czas: "<<passed<<"s"<<endl;

    start = clock();
    file.open("szesc_male.txt");
    counter=0;
    generate("", list, 26, 6, file, counter);
    file.close();
    end = clock();
    passed =double(end-start)/CLOCKS_PER_SEC;
    cout<<"6-"<<counter<<endl;
    cout<<"Czas: "<<passed<<endl;

    cout<<"Male i duze"<<endl;
    start = clock();
    file.open("trzy_male_duze.txt");
    generate("", list2, 52, 3, file, counter);
    file.close();
    end = clock();
    passed = double(end-start)/CLOCKS_PER_SEC;
    cout<<"3-"<<counter<<endl;
    cout<<"Czas: "<<passed<<"s"<<endl;

    start = clock();
    file.open("cztery_male_duze.txt");
    counter=0;
    generate("", list2, 52, 4, file, counter);
    file.close();
    end = clock();
    passed =double(end-start)/CLOCKS_PER_SEC;
    cout<<"4-"<<counter<<endl;
    cout<<"Czas: "<<passed<<"s"<<endl;

    start = clock();
    file.open("piec_male_duze.txt");
    counter=0;
    generate("", list2, 52, 5, file, counter);
    file.close();
    end = clock();
    passed =double(end-start)/CLOCKS_PER_SEC;
    cout<<"5-"<<counter<<endl;
    cout<<"Czas: "<<passed<<"s"<<endl;

    start = clock();
    file.open("szesc_male_duze.txt");
    counter=0;
    generate("", list2, 52, 6, file, counter);
    file.close();
    end = clock();
    passed =double(end-start)/CLOCKS_PER_SEC;
    cout<<"6-"<<counter<<endl;
    cout<<"Czas: "<<passed<<endl;

    cout<<"Wszystkie znaki"<<endl;
    start = clock();
    file.open("trzy_wszystkie.txt");
    generate("", list3, 95, 3, file, counter);
    file.close();
    end = clock();
    passed = double(end-start)/CLOCKS_PER_SEC;
    cout<<"3-"<<counter<<endl;
    cout<<"Czas: "<<passed<<"s"<<endl;

    start = clock();
    file.open("cztery_wszystkie.txt");
    counter=0;
    generate("", list3, 95, 4, file, counter);
    file.close();
    end = clock();
    passed =double(end-start)/CLOCKS_PER_SEC;
    cout<<"4-"<<counter<<endl;
    cout<<"Czas: "<<passed<<"s"<<endl;

    start = clock();
    file.open("piec_wszystkie.txt");
    counter=0;
    generate("", list3, 95, 5, file, counter);
    file.close();
    end = clock();
    passed =double(end-start)/CLOCKS_PER_SEC;
    cout<<"5-"<<counter<<endl;
    cout<<"Czas: "<<passed<<"s"<<endl;

    start = clock();
    file.open("szesc_wszystkie.txt");
    counter=0;
    generate("", list3, 26, 6, file, counter);
    file.close();
    end = clock();
    passed =double(end-start)/CLOCKS_PER_SEC;
    cout<<"6-"<<counter<<endl;
    cout<<"Czas: "<<passed<<endl;
*/
    return 0;
}
