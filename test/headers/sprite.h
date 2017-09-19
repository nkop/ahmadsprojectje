//
// Created by Ahmad Rahimi on 9/5/17.
//

#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <SDL.h>
class Graphics;

class Sprite{
public:
    Sprite();
    Sprite(Graphics &graphics, const std::string &filePath, float posX, float posY, int partnumber);
    virtual ~Sprite();
    virtual void update();
    void draw(Graphics &graphics, float x, float y, double angle);
    SDL_Texture* _sprite;
    int _partnumber;
private:;
    float _x, _y;
};

#endif //SHOOTER_SPRITE_H
