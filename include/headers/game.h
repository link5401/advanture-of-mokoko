#pragma once

#include <iostream>
#include <headers/Entity.h>
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>

enum class GameState {PLAY, EXIT};

class Game {
    public:
        Game();
        ~Game();

        void run();

        GameState getGameState(){return _gameState;}
        SDL_Texture* loadTexture(const char* p_filePath);
        void clear();
        void renderTexture(Entity& p_Entity);
        void displayTexture();
        void handleEvents();
        int getWindowWidth();
        int getWindowHeight();
    private:
        void init(const char* title, int x, int y, int w, int h, Uint32 flags);
      
        SDL_Window* _window;
        SDL_Renderer* _renderer;

        int _screenWidth;
        int _screenHeight;

        GameState _gameState;
};