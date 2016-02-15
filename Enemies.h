#include "Arduboy.h"

#ifndef ENEMIES_H
#define ENEMIES_H
#include "Character.h"
#include "Weapons.h"
class Enemies {
  public:
    Enemies();
    void initEnemies(int *level, Weapons *w, Enemies *e, uint8_t counter, Character *c, Arduboy *a, const unsigned char s[], bool *boolGS);
    Character EnemyArry[6] = {Character( Rect{5, 0 , 8, 8}),
                               Character( Rect{5, 0 , 8, 8}),
                               Character( Rect{5, 0 , 8, 8}),
                               Character( Rect{5, 0 , 8, 8}),
                               Character( Rect{5, 0 , 8, 8}),
                               Character( Rect{5, 0 , 8, 8})
//                               Character( Rect{5, 0 , 8, 8}),
//                               Character( Rect{5, 0 , 8, 8}),
//                               Character( Rect{5, 0 , 8, 8}),
//                               Character( Rect{5, 0 , 8, 8}),
//                               Character( Rect{5, 0 , 8, 8}),
//                               Character( Rect{5, 0 , 8, 8})
                              };
   uint8_t attackIntervals[6]= {2,25,50,75,100,125};
   int level = 0;

  private:

};
#endif
