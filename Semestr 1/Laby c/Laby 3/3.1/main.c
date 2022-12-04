#include <stdio.h>2 #include <stdlib.h>3 #define PI 3.14159  //stale4
#define AUTOR "Jan Kowalski"5
#define  KIERUNEK "Informatyka"6
int main(int argc, char *argv[])
{ //deklaracje8
    const int ROK=1; //stala
    const float PREMIA=0.20;10
    float r, pole, stawka, wyplata;11  int lg;12  //instrukcje13  printf("=========================\n");14  printf("*************************\n");15  printf("=========================\n");16  printf("Programowanie liniowe\n");17  printf("Autor programu: %s,kierunek: %s, rok: %d\n",18         AUTOR, KIERUNEK, ROK);19  printf("=========================\n");20  printf("*************************\n");21  printf("=========================\n");22  printf("Podaj promien kola\n"); scanf("%f",&r);23  pole=PI*r*r;24  printf("Pole kola o promieniu %0.2f = %0.2f\n",25          r,pole);26  printf("=========================\n");27  printf("*************************\n");28  printf("=========================\n");
