#include <SPI.h>
#include <EEPROM.h>
#include "Arduboy.h"
#include "bitmaps.h"
#include "Character.h"
#include "Weapons.h"
#include "Starz.h"
#include "Enemies.h"

bool gameState = 1;
uint8_t i = 0;


Arduboy display;
Weapons weapon;
Enemies enemy;
Starz starz;
Character belknar( Rect{32, 64 , 8, 8});

void setup() {
  SPI.begin();
  display.start();
  display.setTextSize(1);
  display.clearDisplay();
  //intro bitmap
  introFade();
  //display.tunes.playScore(score);
}

void loop() {

  if (!(display.nextFrame())) {
    return;
  }

  if (gameState) {
    // count frames
    weapon.countFrames++;
    //active background starz
    starz.activate(&display);
    // disply kill count
    killCountDisplay (belknar.killCount);
    // enable directions to be implemented
    belknar.enableMovement(&belknar, &display, ship);
    // enable weapon system (at least A BUTTON for now)
    belknar.activateWeapons( &display, bomb);
    // initalize attack phases
    enemy.initEnemies(&enemy.level, &weapon, &enemy, i, &belknar, &display, star, &gameState);

    display.display();
    display.clearDisplay();

  } else {
    gameOver();
  }
  if (!display.tunes.playing()) {
    //display.tunes.playScore(score);
  }
}
//isimple intro bitmap with fade effect
void introFade() {
  display.clearDisplay();
  display.drawBitmap(1, 1, mreData, 128, 64, WHITE);
  display.display();
  delay(2000);

  for (int x = 15; x < 140; x++ ) {
    for (int y = 0; y < 64; y++) {
      display.drawPixel(x, y, 0);
    }
    display.display();
    delay(5);
  }
  delay(1000);
  display.clearDisplay();
}

void killCountDisplay(unsigned short x) {
  display.setCursor(64, 5);
  display.print(x);
}
void killCountDisplayGM(uint8_t x) {
  display.setCursor(58, 50);
  display.print(x);
}

void gameOver() {
  display.tunes.stopScore();
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 22);
  display.write('G');
  display.setCursor(15, 22);
  display.write('A');
  display.setCursor(30, 22);
  display.write('M');
  display.setCursor(45, 22);
  display.write('E');
  display.setCursor(70, 22);
  display.write('O');
  display.setCursor(85, 22);
  display.write('V');
  display.setCursor(100, 22);
  display.write('E');
  display.setCursor(115, 22);
  display.write('R');
  killCountDisplayGM(belknar.killCount);
  display.display();

  resetGame();

}

void resetGame(){

  if (display.pressed(A_BUTTON) && display.pressed(B_BUTTON )){ // press A+B to start new game  
    gameState = 1;
    belknar.killCount = 0;
    Enemies newEnemy;
    enemy = newEnemy;
  
    Character newBelknar( Rect{32, 64 , 8, 8});
    newBelknar.killCount = 0;
    belknar = newBelknar;
    display.setTextSize(1);
  }
}


