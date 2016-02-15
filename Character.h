#include "Arduboy.h"
#include "physics.h"
#include "Weapons.h"
#include "Enemies.h"
#include "bitmaps.h"

#ifndef CHARACTER_H
#define CHARACTER_H

#define MIN 25
#define MAX 65


class Character {
  public:
    Character(Rect r);
    void enableMovement(Character *c, Arduboy *d, const unsigned char a[]);
    void activateWeapons(Arduboy *d, const unsigned char b[]);
    void addAi( Character *c, Arduboy *d, const unsigned char g[], bool *boolGS);
    void aiAttackFormationSin(Character *c, Arduboy *d, const unsigned char s[], bool *boolGS);
    void aiAttackFormationNegSin(Character *c, Arduboy *d, const unsigned char s[], bool *boolGS);
    void aiAttackFormationCos(Character *c, Arduboy *d, const unsigned char s[], bool *boolGS);
    void aiAttackFormationNegCos(Character *c, Arduboy *d, const unsigned char s[], bool *boolGS);
    char characterClass;
    uint8_t strength;
    bool  destructable;
    uint8_t x;
    uint8_t y;
    uint8_t h;
    uint8_t w;
    bool lifeState = 1;
    bool moveState = 1;
    uint8_t killCount;
    float sinX = 0;
    float sinXBackwards = 3.1;
    float cosX = 0;
    float cosXBackwards = 3.1;
    float cosY;
    float sinY;
    Weapons wep;
    uint8_t randO = 0;
    bool randState = 1;
    int getrand(int min, int max);
  private:


    Point dim;
    Physics phy;
};
#endif
