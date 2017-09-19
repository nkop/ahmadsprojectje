//
// Created by Ahmad Rahimi on 9/5/17.
//

#ifndef GAME_H
#define GAME_H

#include "animatedsprite.h"
#include "player.h"

class Graphics;

class Game {
public:
    Game();
    ~Game();
private:
    void gameLoop();
    void draw(Graphics &graphics);
    void update(float elapsedTime);

    Player _player;
};

#endif //SHOOTER_GAME_H
