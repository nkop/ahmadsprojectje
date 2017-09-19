//
// Created by Ahmad Rahimi on 9/5/17.
//
#include "../headers/input.h"
#include "../headers/globals.h"
void Input::beginNewFrame() {
    this->_pressedKeys.clear();
    this->_releasedKeys.clear();
    this->_mousePressedButtons.clear();
    this->_mouseReleasedButtons.clear();
}

void Input::keyDownEvent(const SDL_Event &event) {
    this->_pressedKeys[event.key.keysym.scancode] = true;
    this->_heldKeys[event.key.keysym.scancode] = true;
}

void Input::keyUpEvent(const SDL_Event &event) {
    this->_releasedKeys[event.key.keysym.scancode] = true;
    this->_heldKeys[event.key.keysym.scancode] = false;
}

void Input::mouseDownEvent(const SDL_Event &event) {
    this->_mousePressedButtons[event.button.button] = true;
    this->_mouseHeldButtons[event.button.button] = true;
}

void Input::mouseUpEvent(const SDL_Event &event) {
    this->_mouseReleasedButtons[event.button.button] = true;
    this->_mouseHeldButtons[event.button.button] = false;
}

void Input::mouseMovedEvent(const SDL_Event &event) {
    globals::MOUSEPOSITION_X = event.motion.x;
    globals::MOUSEPOSITION_Y = event.motion.y;
}

bool Input::wasKeyPressed(SDL_Scancode key) {
    return this->_pressedKeys[key];
}

bool Input::wasKeyReleased(SDL_Scancode key) {
    return this->_releasedKeys[key];
}

bool Input::isKeyHeld(SDL_Scancode key) {
    return this->_heldKeys[key];
}

bool Input::wasMouseButtonPressed(Uint8 button) {
    return this->_mousePressedButtons[button];
}

bool Input::wasMouseButtonReleased(Uint8 button) {
    return this->_mouseReleasedButtons[button];
}

bool Input::isMouseButtonHeld(Uint8 button) {
    return this->_mouseHeldButtons[button];
}