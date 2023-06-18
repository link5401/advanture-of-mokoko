#pragma once
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>

#include <iostream>

class KeyboardHandler {
   public:
    KeyboardHandler() {}
    ~KeyboardHandler() {}

   private:
    Uint8* _keyState;
    bool isPressed(SDL_Scancode keycode);
    bool isReleased(SDL_Scancode keycode);
};
// KeyboardHandler::KeyboardHandler() {
    
// }

bool KeyboardHandler::isPressed(SDL_Scancode keycode) {}

bool KeyboardHandler::isReleased(SDL_Scancode keycode) {}

