//--------4 functions for secondary parameters-------------------------------
#include <vcl.h>
#pragma hdrstop

#include "LLMath.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

COMPLEX countGamma(COMPLEX z0, COMPLEX y0)    // returns gamma ( = alf + Jbet)
{
if(y0 == COMPLEX(0,0))
{
  return COMPLEX(0,0);
}
else
  return sqrt(z0*y0);
};
//---------------------------------------------------------------------------

COMPLEX countZ(COMPLEX z0, COMPLEX y0)        // returns Z (wave resistance)
{
  return sqrt(z0/y0);
};
//---------------------------------------------------------------------------

double countVf(double w, double bet)          // returns Vf(wave velocity)
{
  return w/bet;
};
//---------------------------------------------------------------------------

double countLw(double bet)                    // returnsLw(wave length)
{
  return 2*M_PI/bet;
};
//---------------------------------------------------------------------------
