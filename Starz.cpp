#include "Starz.h"

Starz::Starz() {

}
void Starz::activate(Arduboy *d) {

  for (uint8_t i = 0; i < 16; i++) {
      d->drawPixel(bgStars[i].x, bgStars[i].y, WHITE);
      if (bgStars[i].y > 64) {
          bgStars[i].y = 0;
      }
      if (d->everyXFrames(5)) {
        bgStars[i].y++;
      }
    }
}

