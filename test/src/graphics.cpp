//
// Created by Ahmad Rahimi on 9/5/17.
//
#include <SDL.h>
#include "../headers/graphics.h"
#include <SDL_image.h>
#include <iostream>


Graphics::Graphics() {
    SDL_CreateWindowAndRenderer(1080,720,0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "Shooter");
    SDL_Surface* surface = SDL_GetWindowSurface(this->_window);
    _rendercount = 0;
}

Graphics::~Graphics(){
    SDL_DestroyWindow(this->_window);
}

SDL_Surface* Graphics::loadImage(const std::string &filePath) {
    if (this->_spriteSheets.count(filePath) == 0) {
        this->_spriteSheets[filePath] = IMG_Load(filePath.c_str());
    }
    return this->_spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture *texture, SDL_Rect *sourceRectangle, SDL_Rect *destinationRectangle, double angle) {
     if(SDL_RenderCopyEx(this->_renderer, texture, sourceRectangle, destinationRectangle, angle, NULL, SDL_FLIP_HORIZONTAL))
	 {
       std::cout << "blitsurface " << SDL_GetError() << std::endl;
	 }

    //_rendercount += 1;
    //std::cout << std::to_string(_rendercount) << std::endl;
}



void Graphics::flip(){
    SDL_RenderPresent(this->_renderer);
}

void Graphics::clear() {
    SDL_RenderClear(this->_renderer);
}

SDL_Renderer* Graphics::getRenderer() const {
    return this->_renderer;
}