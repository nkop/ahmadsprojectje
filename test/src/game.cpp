//
// Created by Ahmad Rahimi on 9/5/17.
//
#include <iostream>
#include <SDL.h>
#include <thread>
#include <SDL_image.h>
#include "../headers/game.h"

namespace {
    const int FPS = 50;
    const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

Game::Game() {

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "SDL could not initialize! SDL_Error: %s\n" << SDL_GetError() << std::endl;
		return;
	}
    this->gameLoop();
}

Game::~Game() {

}

void Game::gameLoop() {
    Graphics graphics;
    Input input;
    SDL_Event event;
    this->_player = Player(graphics, "player", 300,300, 50);
    int LAST_UPDATE_TIME = SDL_GetTicks();
	int x, y;

    while (true) {
        input.beginNewFrame();
		SDL_GetMouseState(&x, &y);
		this->_player.changeDirection(x, y);
        if (SDL_PollEvent(&event)){
            if (event.type == SDL_KEYDOWN) {
                if(event.key.repeat == 0) {
                    input.keyDownEvent(event);
                }
            }else if (event.type == SDL_KEYUP){
                input.keyUpEvent(event);
            }

            if(event.type == SDL_MOUSEBUTTONDOWN){
                if(event.key.repeat == 0) {
                    input.mouseDownEvent(event);
                }
            }else if(event.type == SDL_MOUSEBUTTONUP){
                input.mouseUpEvent(event);
            }else if(event.type == SDL_MOUSEMOTION){
                input.mouseMovedEvent(event);
                this->_player.changeDirection(event.motion.x, event.motion.y);
            }

            if (event.type == SDL_QUIT){
                return;
            }
        }
        this->_player.checkInput(input, graphics);

        const int CURRENT_TIME_MS = SDL_GetTicks();
        int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
        this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
        LAST_UPDATE_TIME = CURRENT_TIME_MS;
        this->draw(graphics);
    }
}

void Game::draw(Graphics &graphics) {
    graphics.clear();
    this->_player.draw(graphics);
//    this->_player_s.draw(graphics,300,300);
    graphics.flip();
}

void Game::update(float elapsedtime){
    _player.update(elapsedtime);
}