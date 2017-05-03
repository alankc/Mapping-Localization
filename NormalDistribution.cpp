#include "NormalDistribution.h"
#include <cmath>

using namespace std;

double NormalDistribution::Normcdf(double x)
{
  return (0.5 * (1 + erf((x - mu) / (sigma * sqrt(2)))));
}

double NormalDistribution::Normpdf(double x)
{
  return ((1 / (sigma * sqrt( 2 * M_PI))) * exp((-0.5 * (x - mu) * (x - mu)) / (sigma * sigma)));
}

