#include "Arduboy.h"

#ifndef STARZ_H
#define STARZ_H



class Starz {
  public:
    Starz();
    void activate(Arduboy *d);


  private:
  
  struct Point
  {
  public:
      int8_t x;
      int8_t y;
  };

  Point bgStars[16] = {{0,5} , {8,45} , {16,22} , {32,60} , {40,18} , {48,57} , {56,33} , {64,17} , {72,47} , {80,8} , {88,27} , {96,47} , {104,7} , {112,52} , {120,3} , {128,14}};

};
#endif
