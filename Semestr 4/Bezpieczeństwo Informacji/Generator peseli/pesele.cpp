#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool even_month(char x, char y)
{
    string m_s="";
    m_s+=x;
    m_s+=y;
    int m=stoi(m_s);
    if(m==2 || 22) return false;
    else if(m%2==0) return true;
    else return false;
}

bool leap_year(char x, char y)
{
    int y1=x-48;
    int y2=y-48;
    int year=y1+y2;
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    else return false;
}

char ctrSum(string pesel)
{
    int a1 = (pesel[0] - '0');
    int a2 = (pesel[1] - '0') * 3;
    int a3 = (pesel[2] - '0') * 7;
    int a4 = (pesel[3] - '0') * 9;
    int a5 = (pesel[4] - '0');
    int a6 = (pesel[5] - '0') * 3;
    int a7 = (pesel[6] - '0') * 7;
    int a8 = (pesel[7] - '0') * 9;
    int a9 = (pesel[8] - '0');
    int a10 = (pesel[9] - '0') * 3;
    int sum = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10;
    sum = sum % 10;
    if (sum == 0) {
        return '0';
    }
    int ctr = 10 - sum;
    ctr += '0';
    return (char)ctr;
}

int main()
{
    ofstream file("pesele.txt");
    char numbers[10]= {'0','1','2','3','4','5','6','7','8','9'};
    bool leap=false;
    bool even=false;
    string pesel="";
    //01.01.2000-31.03.2022
    for(int i=2;i>=0;i--){//rok
        for(int j=9;j>=0;j--){//rok
            if(i==2 && j > 2) continue;
            leap = leap_year(numbers[i], numbers[j]);
            for(int k=3;k>=2;k--){//miesiac
                for(int l=9;l>=0;l--){//miesiac
                    if(i==2 && j==2 && (l > 3 || k > 2)) continue;
                    if(k==3 && l > 2) continue;
                    if(k==2 && l == 0) continue;
                    even = even_month(numbers[k], numbers[l]);
                    for(int m=3;m>=0 ;m--){//dzien
                            for(int n=9;n>=0;n--){//dzien
                                if(m==0 && n == 0) continue;
                                if(m==3 && n > 1) continue;
                                if(m==3 && n==1 && even) continue;
                                if(l==2 && k==2 && m==2 && n==9 && !leap) continue;
                                for(int o=9;o>=0;o--){
                                    for(int p=9;p>=0;p--){
                                        for(int q=9;q>=0;q--){
                                            for(int r=9;r>=0;r--){
                                                  pesel += numbers[i];
                                                  pesel += numbers[j];
                                                  pesel += numbers[k];
                                                  pesel += numbers[l];
                                                  pesel += numbers[m];
                                                  pesel += numbers[n];
                                                  pesel += numbers[o];
                                                  pesel += numbers[p];
                                                  pesel += numbers[q];
                                                  pesel += numbers[r];
                                                  char ctr = ctrSum(pesel);
                                                  pesel+=ctr;
                                                  file<<pesel<<endl;
                                                  pesel = "";
    }}}}}}}}}}
    //01.01.1970-31.12.1999
    for(int i=9;i>=0;i--){//rok
        for(int j=9;j>=0;j--){//rok
            leap = leap_year(numbers[i], numbers[j]);
            for(int k=1;k>=0;k--){//miesiac
                for(int l=9;l>=0;l--){//miesiac
                    if(k==1 && l > 2) continue;
                    if(k==0 && l == 0) continue;
                    even = even_month(numbers[k], numbers[l]);
                    for(int m=3;m>=0 ;m--){//dzien
                            for(int n=9;n>=0;n--){//dzien
                                if(m==0 && n == 0) continue;
                                if(m==3 && n > 1) continue;
                                if(m==3 && n==1 && even) continue;
                                if(l==2 && k==0 && m==2 && n==9 && !leap) continue;
                                for(int o=9;o>=0;o--){
                                    for(int p=9;p>=0;p--){
                                        for(int q=9;q>=0;q--){
                                            for(int r=9;r>=0;r--){
                                                  pesel += numbers[i];
                                                  pesel += numbers[j];
                                                  pesel += numbers[k];
                                                  pesel += numbers[l];
                                                  pesel += numbers[m];
                                                  pesel += numbers[n];
                                                  pesel += numbers[o];
                                                  pesel += numbers[p];
                                                  pesel += numbers[q];
                                                  pesel += numbers[r];
                                                  char ctr = ctrSum(pesel);
                                                  pesel+=ctr;
                                                  file<<pesel<<endl;
                                                  pesel = "";
    }}}}}}}}}}
    file.close();
    return 0;
}
