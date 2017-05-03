/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lms200.h
 * Author: x
 *
 * Created on 28 de Abril de 2017, 13:32
 */

#ifndef LMS200_H
#define LMS200_H

#include <libplayerc++/playerc++.h>
#include <libplayerinterface/player.h>

using namespace PlayerCc;

class Lms200 : public RangerProxy {
public:

    Lms200(PlayerClient *aPc, uint32_t aIndex = 0) : RangerProxy(aPc, aIndex) {
    }
    double GetBetha(uint32_t index);
    double GetProbability(player_pose2d_t& position, MapProxy& map);
private:
    const double betha[9] = {12.0, 16.4, 20.8, 25.2, 29.6, 34.0, 38.4, 42.8, 47.2};
    const double zHit = 1.0;
    const double zShort = 1.0;
    const double zMax = 8.0;
    const double zRand = 1.0;
    const double sigmaHit = 0.1;
    const double lambdaShort = 0.1;
    void CalculateZStar(player_pose2d_t& position, MapProxy& map, double zStar[]);
    double PHit(uint32_t index, double zStar[]);
    double PShort(uint32_t index, double zStar[]);
    double PMax(uint32_t index, double zStar[]);
    double PRand(uint32_t index, double zStar[]);
};

#endif /* LMS200_H */

