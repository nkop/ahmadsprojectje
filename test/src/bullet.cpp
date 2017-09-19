//
// Created by Ahmad Rahimi on 9/7/17.
//

#include "../headers/helper.h"
#include "../headers/bullet.h"

namespace bullet_constants {
    const float BULLET_SPEED = 0.8f;
}

Bullet::Bullet() {}

Bullet::Bullet(Graphics &graphics, std::string objectName, float x, float y, int timeToUpdate, double _dir) : AnimatedSprite(objectName, x ,y, timeToUpdate) {
    this->setupAnimation(graphics);
    this->playAnimation("bullet_type_1");
    this->_corrected_angle = Helper::correctTheAngle(_dir);
    this->_dir = _dir;
    this->_x = x;
    this->_y = y;
}

void Bullet::setupAnimation(Graphics &graphics) {
    this->addAnimation(graphics, 0, "bullet_type_1");
}

void Bullet::draw(Graphics &graphics) {
//    try {
//        if (this->_sprite._sprite != NULL) {
            AnimatedSprite::drawsprite(graphics, this->_x, this->_y, this->_dir);
//        }
//    }catch (int e){
//        std::cout << "An exception occurred. Exception Nr. " << e << '\n';
//    }
}

void Bullet::update(float elapsedTime) {
    double correctedAngleRadians = Helper::degreesToRadians(this->_corrected_angle);
    this->_dx = bullet_constants::BULLET_SPEED * sin(correctedAngleRadians);
    this->_dy = bullet_constants::BULLET_SPEED * -cos(correctedAngleRadians);
    //movement times elapsedtime so we fill slower/faster framerate gaps
    this->_x += this->_dx * elapsedTime;
    this->_y += this->_dy * elapsedTime;

    AnimatedSprite::update(elapsedTime);
}

void Bullet::animationDone(std::string currentAnimation) {

}

void Bullet::animationEnded() {

}