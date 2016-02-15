#include "Enemies.h"

Enemies::Enemies() {
}

void Enemies::initEnemies(int *level, Weapons *w, Enemies *e, uint8_t counter, Character *c, Arduboy *a, const unsigned char s[], bool *boolGS) {
    
  
   if (w->countFrames > 100 && level == 0) {
      e->level = c->getrand(1, 11);
      w->countFrames = 0;
      for (int i = 0; i < 6; i++) {
        e->EnemyArry[i] = Character( Rect{ -60, -60 , 8, 8});
      }
    }
    if (w->countFrames > 250 && level != 0 ) {
      e->level = c->getrand(1, 11);
      
      w->countFrames = 0;

      for (int i = 0; i < 6; i++) {
        e->EnemyArry[i] = Character( Rect{ -60, -60 , 8, 8});
      }
    }

  switch ( e->level )
  {
    case 1 :
      for (uint8_t j = 0; j < 6; j++) {
        if (w->countFrames > attackIntervals[j]) {
          e->EnemyArry[counter++].aiAttackFormationSin(c, a, s, boolGS);
        }
      }
      counter = 0;
      break;
    case 2:
      for (uint8_t j = 0; j < 6; j++) {
        if (w->countFrames > attackIntervals[j]) {
          e->EnemyArry[counter++].aiAttackFormationNegSin(c, a, s, boolGS);
        }
      }
      counter = 0;
      break;
    case 3:
      for (uint8_t j = 0; j < 6; j++) {
        if (w->countFrames > attackIntervals[j]) {
          if (j % 2 == 0) {
            e->EnemyArry[counter++].aiAttackFormationSin(c, a, s, boolGS);
          } else {
            e->EnemyArry[counter++].aiAttackFormationNegSin(c, a, s, boolGS);
          }
        }
      }
      counter = 0;
      break;
    case 4:
      for (uint8_t j = 0; j < 6; j++) {
        if (w->countFrames > attackIntervals[j]) {
          e->EnemyArry[counter++].aiAttackFormationCos(c, a, s, boolGS);
        }
      }
      counter = 0;
      break;
    case 5:
      for (uint8_t j = 0; j < 6; j++) {
        if (w->countFrames > attackIntervals[j]) {
          e->EnemyArry[counter++].aiAttackFormationNegCos(c, a, s, boolGS);
        }
      }
      counter = 0;
      break;
    case 6:
      for (uint8_t j = 0; j < 6; j++) {
        if (w->countFrames > attackIntervals[j]) {
          if (j % 2 == 0) {
            e->EnemyArry[counter++].aiAttackFormationCos(c, a, s, boolGS);
          } else {
            e->EnemyArry[counter++].aiAttackFormationNegCos(c, a, s, boolGS);
          }
        }
      }
      counter = 0;
      break;
    case 7:
      for (uint8_t j = 0; j < 6; j++) {
        if (w->countFrames > attackIntervals[j]) {
          if (j % 2 == 0) {
            e->EnemyArry[counter++].aiAttackFormationSin(c, a, s, boolGS);
          } else {
            e->EnemyArry[counter++].aiAttackFormationCos(c, a, s, boolGS);
          }
        }
      }
      counter = 0;
      break;
    case 8:
      for (uint8_t j = 0; j < 6; j++) {
        if (w->countFrames > attackIntervals[j]) {
          if (j % 2 == 0) {
            e->EnemyArry[counter++].aiAttackFormationNegSin(c, a, s, boolGS);
          } else {
            e->EnemyArry[counter++].aiAttackFormationNegCos(c, a, s, boolGS);
          }
        }
      }
      counter = 0;
      break;
    case 9:
      for (uint8_t j = 0; j < 6; j++) {
        if (w->countFrames > attackIntervals[j]) {
          if (j % 2 == 0) {
            e->EnemyArry[counter++].aiAttackFormationSin(c, a, s, boolGS);
          } else {
            e->EnemyArry[counter++].aiAttackFormationNegCos(c, a, s, boolGS);
          }
        }
      }
      counter = 0;
      break;
    case 10:
      for (uint8_t j = 0; j < 6; j++) {
        if (w->countFrames > attackIntervals[j]) {
          if (j % 2 == 0) {
            e->EnemyArry[counter++].aiAttackFormationNegSin(c, a, s, boolGS);
          } else {
            e->EnemyArry[counter++].aiAttackFormationCos(c, a, s, boolGS);
          }
        }
      }
      counter = 0;
      break;
  }
}
