#include "Math.h"
#include<stdio.h>
#include<stdarg.h>
#include<cstring>

#define _CRT_SECURE_NO_WARNINGS



int Math::Add(int x, int y)
{
    return x + y;
}

int Math::Add(int x, int y, int z)
{
    return x + y + z;
}

int Math::Add(double x, double y)
{
    return x + y;
}

int Math::Add(double x, double y, double z)
{
    return x + y + z;
}

int Math::Mul(int x, int y)
{
    return x * y;
}

int Math::Mul(int x, int y, int z)
{
    return x * y * z;
}

int Math::Mul(double x, double y)
{
    return x * y;
}

int Math::Mul(double x, double y, double z)
{
    return x * y * z;

}

int Math::Add(int count, ...)
{
    va_list args;
    va_start(args, count);

    int S = 0;
    for (int i = 0; i < count; i++)
        S += va_arg(args, int);

    va_end(args);
    return S;
}

 char* Math::Add(const char* x, const char* y)
{
     if (x == nullptr || y == nullptr)
         return nullptr;
    char* xx = new char[sizeof(x)];
    char* yy = new char[sizeof(y)];
    xx = (char*)x;
    yy = (char*)y;
   
    strcat(xx, yy);
    return xx;

}

 
