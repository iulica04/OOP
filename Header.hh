#pragma once

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


enum VALORI {
	INMULTIRE = 0,
	SUMA,          //1
	REZERVAT1,      //2
	DIFERENTA,    //3 ...
	REZERVAT2,
	IMPARTIRE
};

typedef int (*func)(int, int);

struct Content {
	int p1;
	int p2;
};

int Sum(int a, int b);
int Dif(int a, int b);
int Mul(int a, int b);
int Div(int a, int b);



