//
// Created by Ahmad Rahimi on 9/5/17.
//

#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <map>
#include "sprite.h"
#include "graphics.h"

class Graphics;

class AnimatedSprite {
public:
    AnimatedSprite();
    AnimatedSprite(const std::string &objectName, float posX, float posY, float timeToUpdate);

    void playAnimation(std::string animation, bool loop = true);

    void playExtraAnimation(std::string animation, bool loop = true);

    void update(float elapsedTime);

    void drawsprite(Graphics &graphics, float x, float y, double angle);

protected:
    double _timeToUpdate;
    bool _currentAnimationLoop;
    std::string _currentAnimation;
    std::string _objectName;
    Sprite _sprite;

    void addAnimation(Graphics &graphics, int maxFrames, std::string name);
    void addExtraAnimation(Graphics &graphics, int maxFrames, std::string name, int partnumber);

    void resetAnimations();

    void stopAnimations();

    void setVisisble(bool visible);


    // = 0, omdat deze functies alleen beschikbaar moeten zijn van klasses die inheriten van animatedsprite klasse
    virtual void animationDone(std::string currentAnimation) = 0;

    virtual void animationEnded() = 0;

    virtual void setupAnimation(Graphics &graphics) = 0;
private:
    std::map<std::string, std::map<int, Sprite> > _animations;
    std::map<std::string, std::map<int, Sprite> > _extraAnimations;
    std::map<std::string, int > _extraAnimationsPlaying;

    int _frameIndex;
    double _timeElapsed;
    bool _visible;
};

#endif //ANIMATEDSPRITE_H
