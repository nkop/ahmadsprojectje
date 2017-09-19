//
// Created by Ahmad Rahimi on 9/5/17.
//

#include "../headers/sprite.h"
#include "../headers/graphics.h"
#include <iostream>
Sprite::Sprite() {}

Sprite::Sprite(Graphics &graphics, const std::string &filePath, float posX, float posY, int partnumber) : _x(posX), _y(posY), _partnumber(partnumber) {
    this->_sprite = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));

    if (this->_sprite == NULL){
        printf(SDL_GetError());
    }
}

Sprite::~Sprite() {}

void Sprite::draw(Graphics &graphics, float x, float y, double angle) {
    try {
        int w, h;
        SDL_QueryTexture(this->_sprite, NULL, NULL, &w, &h);
        SDL_Rect destinationRectangle = {int(x), int(y), w, h};
        graphics.blitSurface(this->_sprite, NULL, &destinationRectangle, angle);
    }catch (int e){
        std::cout << "An exception occurred. Exception Nr. " << e << '\n';
    }
}

void Sprite::update() {

}