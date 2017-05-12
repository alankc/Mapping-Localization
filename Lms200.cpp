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

double Lms200::PHit(uint32_t index, double zStar[])
{
  if ((0 <= this->GetRange(index)) && (this->GetRange(index) <= zMax))
  {
    NormalDistribution nd(zStar[index], sigmaHit);
    return ((1 / nd.Normcdf(this->GetRange(index))) * nd.Normpdf(this->GetRange(index)));
  } else
    return 0.0;
}

double Lms200::PShort(uint32_t index, double zStar[])
{
  if ((0 <= this->GetRange(index)) && (this->GetRange(index) <= zStar[index]))
  {
    double n = 1 / (1 - exp(- lambdaShort * zStar[index]));
    return (n * lambdaShort * exp(- lambdaShort * this->GetRange(index)));
  } else
    return 0.0;
}

double Lms200::PMax(uint32_t index, double zStar[])
{
  if (this->GetRange(index) == zMax)
    return 1.0;
  else
    return 0.0;
}

double Lms200::PRand(uint32_t index, double zStar[])
{
  if ((0 <= this->GetRange(index)) && (this->GetRange(index) < zMax))
    return (1 / zMax);
  else
    return 0.0;
}

double Lms200::GetProbability (player_pose2d_t& position, MapProxy& map)
{
  double zStar[180], probability = 1.0, temporaryProbability;

  CalculateZStar(position, map, zStar);

  for (uint8_t i = 0; i < 180; i++)
  {
    temporaryProbability = zHit * PHit(i, zStar) + zShort * PShort(i, zStar) +
            zMax * PMax(i, zStar) + zMax * PMax(i, zStar);
    probability = probability * temporaryProbability;
  }

  return probability;
}

void Lms200::CalculateZStar(player_pose2d_t& position, MapProxy& map, double zStar[])
{
  //AMANATIDES,  J., AND WOO,  A.   1987.   A fast voxel traversal algorithm for ray tracing. In Eurographics 1987, 3–10.
  int8_t stepX, stepY, pixel;
  int x, y;
  double tDeltaX, tDeltaY, tMaxX, tMaxY, dX, dY, xEndOfLine, yEndOfLine;

  tDeltaX = tDeltaY = map.GetResolution();

  for (uint8_t i = 0; i < 181; i++)
  {
    xEndOfLine = position.px + 8.0 * cos((position.pa + 90.0 - i) * M_PI / 180.0);
    yEndOfLine = position.py + 8.0 * sin((position.pa + + 90.0 - i) * M_PI / 180.0);
    

    dX = xEndOfLine - position.px;
    dY = yEndOfLine - position.py;

    tMaxY = tMaxX = sqrt( 2 * (map.GetResolution() / 2) * (map.GetResolution() / 2)); //Approximation to make more fast

    if (dX > 0)      //Line to Rigth
      stepX = 1;
    else if (dX < 0) //Line to Left
      stepX = -1;
    else
      stepX = 0;

    if (dY > 0)      //Line to Up
      stepY = 1;
    else if (dY < 0) //Line to Down
      stepY = -1;
    else
      stepY = 0;

    x = position.px;
    y = position.py;
    pixel = 0;
    while ((pixel != 1) && ((abs((int)xEndOfLine - x) > 1) || (abs((int)yEndOfLine - y) > 1)))
    {
      pixel = map.GetCell(x, y);
      if (tMaxX < tMaxY)
      {
        tMaxX = tMaxX + tDeltaX;
        x = x + stepX;
      } else
      {
        tMaxY = tMaxY + tDeltaY;
        y = y + stepY;
      }   
    }
    
    zStar[i] = sqrt(pow(x - position.px, 2) + pow(y - position.py, 2));
    
  }
  //Based in Bresenham Algorithm
  /*int8_t slope;
  int32_t dx, dy, incE, incNE, d, x, y, x1, x2[181], y1, y2[181];

  x1 = (int32_t) (position.px / map.GetResolution());
  y1 = (int32_t) (position.py / map.GetResolution());

  for (uint8_t i = 0; i < 181; i++)
  {
    x2[i] = x1 + 8.0 * cos();
    y2[i] = y1 + 8.0 * ;

    dx = x2 - x1;
    dy = y2 - y1;

    if (dy < 0)
    {
      slope = -1;
      dy = -dy;
    } else
    {
      slope = 1;
    }
    //Bresenham constant
    incE = 2 * dy;
    incNE = 2 * dy - 2 * abs(dx);
    d = 2 * dy - abs(dx);
    y = y1;

    int8_t pixel;
    if (dx > 0) //Line to right
    {
      for (x = x1; x <= x2; x++)
      {
        pixel = map.GetCell(x, y);
        if (d <= 0)
        {
          d += incE;
        } else
        {
          d += incNE;
          y += slope;
        }
      }
    } else if (dx < 0) //Line to left
    {
      for (x = x1; x >= x2; x--)
      {
        pixel = map.GetCell(x, y);
        if (d <= 0)
        {
          d += incE;
        } else
        {
          d += incNE;
          y += slope;
        }
      }
    } else //Vertical Line
    {
      if (dy > 0)
      {
        for (y = y1; y <= y2; y++)
        {
          pixel = map.GetCell(x1, y);
        }
      } else
      {
        for (y = y1; y >= y2; y--)
        {
          pixel = map.GetCell(x1, y);
        }
      }

    }
  }*/

}