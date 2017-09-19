//
// Created by Ahmad Rahimi on 9/7/17.
//

#ifndef BULLET_H
#define BULLET_H

#include "animatedsprite.h"
#include "graphics.h"

class Bullet : AnimatedSprite {
public:
    Bullet();
    Bullet(Graphics &graphics, std::string objectName, float x, float y, int timeToUpdate, double angle);
    void draw(Graphics &graphics);
    void update(float elapsedTime);
    virtual void animationDone(std::string currentAnimation);
    virtual void animationEnded();
    virtual void setupAnimation(Graphics &graphics);
private:
protected:
    float _dx, _dy, _x, _y;
    double _dir;
    double _rad;
    double _corrected_angle;
};
#endif //BULLET_H
