#include "Lms200.h"
#include "NormalDistribution.h"
#include <cmath>

using namespace std;

double Lms200::GetBetha(uint32_t index)
{
  if (index > 179)
    index = 179;
  //Resultando dos valores de betha
  return (12.0 + 4.4 * this->GetRange(index));
}

double Lms200::PHit(uint32_t index)
{
  if((0 <= this->GetRange(index)) && (this->GetRange(index) <= zMax))
  {
    NormalDistribution nd(zStar[index], sigmaHit);
    return ((1 / nd.Normcdf(this->GetRange(index))) * nd.Normpdf(this->GetRange(index)));
  }
  else
    return 0.0;
}

double Lms200::PShort(uint32_t index)
{
  if((0 <= this->GetRange(index)) && (this->GetRange(index) <= zStar[index]))
  {
    double n = 1 / (1 - exp(- lambdaShort * zStar[index]));  
    return (n * lambdaShort * exp(- lambdaShort * this->GetRange(index)));
  }
  else
    return 0.0;
}

double Lms200::PMax(uint32_t index)
{
  if(this->GetRange(index) == zMax)
    return 1.0;
  else
    return 0.0;
}

double Lms200::PRand(uint32_t index)
{
  if((0 <= this->GetRange(index)) && (this->GetRange(index) < zMax))
    return (1 / zMax);
  else
    return 0.0;
}


