//
// Created by Ahmad Rahimi on 9/6/17.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <array>
#include "animatedsprite.h"
#include "input.h"
#include "bullet.h"

class Graphics;

class Player : public AnimatedSprite{
public:
    Player();
    Player(Graphics &graphics, std::string objectName, float x, float y, int timeToUpdate);
    void draw(Graphics &graphics);
    void update(float elapsedTime);
    void changeDirection(float toX, float toY);
    void movePlayerLeft(std::string doAction);
    void movePlayerRight(std::string doAction);
    void movePlayerBack(std::string doAction);
    void movePlayerForward(std::string doAction);
    void shootWeapon(Graphics &graphics);
    void stopShooting();
    void reloadWeapon();
    void stopPlayer();
    void checkInput(Input input, Graphics &graphics);

    virtual void animationDone(std::string currentAnimation);
    virtual void animationEnded();
    virtual void setupAnimation(Graphics &graphics);

    float _dx, _dy, _x, _y;
    double _dir;
    double _rad;
    double _corrected_angle;

private:
    bool waitForPrevAnimation;
    void doReloadOrShoot(std::string doAction);
    std::map<int, Bullet> bullets;
};

#endif //SHOOTER_PLAYER_H
