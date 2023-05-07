//---------------------------------------------------------------------------
#ifndef LLMathH
#define LLMathH
#include <complex.h>

#define COMPLEX complex <double>
//---------------------------------------------------------------------------
COMPLEX countGamma(COMPLEX,COMPLEX);    // returns gamma ( = alf + Jbet)
COMPLEX countZ(COMPLEX,COMPLEX);        // returns Z (wave resistance)
double countVf(double, double);          // returns Vf(wave velocity)
double countLw(double);                    // returnsLw(wave length)
#endif

