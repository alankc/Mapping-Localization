#include "OccupancyGridMapping.hpp"

OccupancyGridMapping::OccupancyGridMapping(const int heigth, const int width, Lms200& s) : s(s)
{
  mapa = Mat::zeros(heigth, width, CV_8UC3);
}

void OccupancyGridMapping::OccupancyGridMapUpdate(player_pose2d_t position)
{
  
  //line(mapa, Point( 0, 0 ), Point( position.px, position.py), Scalar( 110, 220, 0 ),  2, 8 );
  //namedWindow("Gray", CV_WINDOW_AUTOSIZE);
  //imshow("Gray", mapa); 
  //waitKey(100);  
}

void OccupancyGridMapping::InverseSensorModel(player_pose2d_t position)
{
  //cel center-of-mass 
  double xi = 0;
  double yi = 0;

  double r = 0;
  double phi = 0;
  double k = 0;



}

void OccupancyGridMapping::UpdatePerceivedCells()
{
  for (uint8_t i = 0; i < 180; i++)
  {
    //perceivedCells[i].px
  }
}

OccupancyGridMapping::~OccupancyGridMapping()
{
  mapa.deallocate();
}

