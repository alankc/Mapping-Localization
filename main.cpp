#include <iostream>
#include <libplayerc++/playerc++.h>
#include <libplayerinterface/player.h>
#include "Lms200.h"
//#include "OccupancyGridMapping.hpp"

using namespace PlayerCc;
using namespace std;

int main(int argc, char** argv)
{
  PlayerClient a("localhost");
  Lms200 b(&a, 1);



  while (true)
  {
    a.Read();

    if (b.IsValid())
    {
      cout << "Leituras: ";
      for (uint32_t i = 0; i < 180; i++)
        cout << b.GetBetha(i) << " ";

      cout << endl;
    }

  }


  return 0;
}

