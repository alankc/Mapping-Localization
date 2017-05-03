#ifndef OCCUPANCYGRIDMAP_HPP
#define OCCUPANCYGRIDMAP_HPP

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <libplayerinterface/player.h>
#include "Lms200.h"

using namespace cv;

class OccupancyGridMapping {
public:
    OccupancyGridMapping(const int heigth, const int width, Lms200& s);
    void OccupancyGridMapUpdate(player_pose2d_t position);
    virtual ~OccupancyGridMapping();
private:
    Mat mapa;
    Lms200& s;
    player_point_2d perceivedCells[180];
    void InverseSensorModel(player_pose2d_t position);
    void UpdatePerceivedCells();
};



#endif

