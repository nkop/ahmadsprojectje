//
// Created by Ahmad Rahimi on 9/5/17.
//

#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>
#include <map>

class Input {
public:
    void beginNewFrame();
    void keyUpEvent(const SDL_Event& event);
    void keyDownEvent(const SDL_Event& event);
    void mouseDownEvent(const SDL_Event& event);
    void mouseUpEvent(const SDL_Event& event);
    void mouseMovedEvent(const SDL_Event& event);

    bool wasKeyPressed(SDL_Scancode key);
    bool wasKeyReleased(SDL_Scancode key);
    bool isKeyHeld(SDL_Scancode key);
    bool wasMouseButtonPressed(Uint8 button);
    bool wasMouseButtonReleased(Uint8 button);
    bool isMouseButtonHeld(Uint8 button);
private:
    std::map<SDL_Scancode, bool> _heldKeys;
    std::map<SDL_Scancode, bool> _pressedKeys;
    std::map<SDL_Scancode, bool> _releasedKeys;
    std::map<Uint8, bool> _mousePressedButtons;
    std::map<Uint8, bool> _mouseReleasedButtons;
    std::map<Uint8, bool> _mouseHeldButtons;
};

#endif //SHOOTER_INPUT_H
