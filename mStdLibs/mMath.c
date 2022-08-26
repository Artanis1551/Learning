#include "mMath.h"

void Swapi(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Swapc(char* x, char* y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

void Swapuc(unsigned char* x, unsigned char* y)
{
    unsigned char temp = *x;
    *x = *y;
    *y = temp;
}

void Swapd(double* x, double* y)
{
    double temp = *x;
    *x = *y;
    *y = temp;
}

void Swapf(float* x, float* y)
{
    float temp = *x;
    *x = *y;
    *y = temp;
}

void Swapll(long long* x, long long* y)
{
    long long temp = *x;
    *x = *y;
    *y = temp;
}

void Swapl(long* x, long* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}