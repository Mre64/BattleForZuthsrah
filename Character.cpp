#include "Character.h"

Character::Character(Rect r) {

  x = r.x;
  y = r.y;
  h = r.height;
  w = r.width;
}


void Character::enableMovement(Character *c, Arduboy *d, const unsigned char a[]) {
  dim.x = c->y;
  dim.y = c->x;

  d->drawBitmap(c->y, c->x, a, c->w, c->h, WHITE);

  if (d->pressed(UP_BUTTON) && (!phy.collide(dim, TOP_EDGE))) {
    c->x = c->x - 2;
  } else if (d->pressed(DOWN_BUTTON) && (!phy.collide(dim, BOTTOM_EDGE))) {
    c->x = c->x + 2;
  } else if (d->pressed(LEFT_BUTTON) && (!phy.collide(dim, LEFT_EDGE))) {
    c->y = c->y - 2;
  } else if (d->pressed(RIGHT_BUTTON) && (!phy.collide(dim, RIGHT_EDGE))) {
    c->y = c->y + 2;
  }
}

void Character::activateWeapons(Arduboy *d, const unsigned char b[]) {
  wep.countFrames++;
  Point dim{wep.y, wep.x};

  if (wep.shootBullet) {
    d->drawPixel(wep.y, wep.x, WHITE);

    if (phy.collide(dim, TOP_EDGE)) {
      wep.x = 0;
      wep.shootBullet = 0;

    } else {

      wep.x = wep.x - 2;
    }
  } else if (wep.shootBomb) {
    d->drawBitmap(wep.y, wep.x, b, 8, 8, WHITE);

    if (phy.collide(dim, TOP_EDGE)) {
      wep.x = 0;
      wep.shootBomb = 0;

    } else {
      wep.x = wep.x - 2;
    }
  }

  if (d->pressed(A_BUTTON) && wep.countFrames > 30  && !d->pressed(B_BUTTON)) {
    wep.x = x + 4;
    wep.y = y + 4;
    wep.shootBullet = 1;
    wep.countFrames = 0;
    d->tunes.playScore(laser);

  } else if (d->pressed(B_BUTTON) && wep.countFrames > 30  && !d->pressed(A_BUTTON)) {
    wep.x = x ;
    wep.y = y ;
    wep.shootBomb = 1;
    wep.countFrames = 0;
  }
}

void Character::addAi( Character *c, Arduboy *d, const unsigned char g[], bool *boolGS) {

  Rect mainC = {c->y, c->x, c->h, c->w};
  Rect bel = {c->wep.y, c->wep.x, 1, 1};
  Rect ai = {y, x, h, w};

  if (lifeState) {
    d->drawBitmap(y, x, g, 8, 8, WHITE);
    if (x < 2 || x > 55) {
      moveState = !moveState;
    }
    if (moveState) {
      x = x + 1;
    } else {
      x = x - 1;
    }
  }
  if (phy.collide(ai, bel)) {
    lifeState = 0;
    y = 66;
    c->killCount = c->killCount + 1;
  }
  if (phy.collide(ai, mainC)) {
    *boolGS = 0;
  }
}

void Character::aiAttackFormationSin(Character *c, Arduboy *d, const unsigned char s[], bool *boolGS) {
  wep.countFrames++;
  Rect mainC = {c->y, c->x, c->h, c->w};
  Rect bel = {c->wep.y, c->wep.x, 1, 1};
  Rect ai = {x, y, h, w};

  if (randState) {
    randO = getrand(MIN, MAX);
    randState = 0;
  }

  if (lifeState) {
    d->drawBitmap(x, y, s , w, h, WHITE);

    if (d->everyXFrames(2)) {
      if (sinX <= 3.1) {
        sinX += 0.05;
        sinY = sin(sinX);
        x =  (int)(sinX * 41);
        y =  (int)(sinY * randO);
      }
    }
  }
  if (phy.collide(ai, bel)) {
    lifeState = 0;
    y = 166;
    c->killCount = c->killCount + 1;
  }
  if (phy.collide(ai, mainC)) {
    *boolGS = 0;
  }
  if (wep.countFrames > 250) {
    wep.countFrames = 0;
    sinX = 0;
    randState = 1;
    lifeState = 1;
  }
}
void Character::aiAttackFormationNegSin(Character *c, Arduboy *d, const unsigned char s[], bool *boolGS) {
  wep.countFrames++;
  Rect mainC = {c->y, c->x, c->h, c->w};
  Rect bel = {c->wep.y, c->wep.x, 1, 1};
  Rect ai = {x, y, h, w};

  if (randState) {
    randO = getrand(MIN, MAX);
    randState = 0;
  }

  if (lifeState) {
    d->drawBitmap(x, y, s , w, h, WHITE);

    if (d->everyXFrames(2)) {
      if (sinXBackwards >= 0) {
        sinXBackwards -= 0.05;
        sinY = sin(sinXBackwards);
        x =  (int)(sinXBackwards * 41);
        y =  (int)(sinY * randO);
      }
    }
  }
  if (phy.collide(ai, bel)) {
    lifeState = 0;
    y = 166;
    c->killCount = c->killCount + 1;
  }
  if (phy.collide(ai, mainC)) {
    *boolGS = 0;
  }
  if (wep.countFrames > 250) {
    wep.countFrames = 0;
    sinXBackwards = 3.1;
    randState = 1;
    lifeState = 1;
  }
}
void Character::aiAttackFormationCos(Character *c, Arduboy *d, const unsigned char s[], bool *boolGS) {
  wep.countFrames++;
  Rect mainC = {c->y, c->x, c->h, c->w};
  Rect bel = {c->wep.y, c->wep.x, 1, 1};
  Rect ai = {x, y, h, w};

  if (randState) {
    randO = getrand(MIN, MAX);
    randState = 0;
  }

  if (lifeState) {
    d->drawBitmap(x, y, s , w, h, WHITE);

    if (d->everyXFrames(2)) {
      if (sinX <= 3.1) {
        sinX += 0.05;
        sinY = cos(sinX);
        x =  (int)(sinX * 41);
        y =  (int)(sinY * randO);
      }
    }
  }
  if (phy.collide(ai, bel)) {
    lifeState = 0;
    y = 166;
    c->killCount = c->killCount + 1;
  }
  if (phy.collide(ai, mainC)) {
    *boolGS = 0;
  }
  if (wep.countFrames > 250) {
    wep.countFrames = 0;
    sinX = 0;
    randState = 1;
    lifeState = 1;
  }
}
void Character::aiAttackFormationNegCos(Character *c, Arduboy *d, const unsigned char s[], bool *boolGS) {
  wep.countFrames++;
  Rect mainC = {c->y, c->x, c->h, c->w};
  Rect bel = {c->wep.y, c->wep.x, 1, 1};
  Rect ai = {x, y, h, w};

  if (randState) {
    randO = getrand(MIN, MAX);
    randState = 0;
  }

  if (lifeState) {
    d->drawBitmap(x, y, s , w, h, WHITE);

    if (d->everyXFrames(2)) {
      if (sinXBackwards >= 0) {
        sinXBackwards -= 0.05;
        sinY = cos(sinXBackwards);
        x =  (int)(sinXBackwards * 41);
        y =  (int)(sinY * randO);
      }
    }
  }
  if (phy.collide(ai, bel)) {
    lifeState = 0;
    y = 166;
    c->killCount = c->killCount + 1;
  }
  if (phy.collide(ai, mainC)) {
    *boolGS = 0;
  }
  if (wep.countFrames > 250) {
    wep.countFrames = 0;
    sinXBackwards = 3.1;
    randState = 1;
    lifeState = 1;
  }
}
int Character::getrand(int min, int max) {
  return (rand() % (max - min) + min);
}

