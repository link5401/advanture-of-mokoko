#pragma once
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>

#include <headers/Entity.hpp>
#include <headers/Character.hpp>
#include <headers/tileMap.hpp>
#include <iostream>

enum class GameState { PLAY, EXIT };

class Game {
   public:
    Game();
    ~Game();

    GameState getGameState() { return _gameState; }

    SDL_Texture *loadTexture(const char *p_filePath);

    void clear();
    void renderBackground(Entity &p_Entity);
    void renderTexture(Entity &p_Entity, SDL_Rect cameraRect);
    void renderCharacter(Character &p_Character, SDL_Rect cameraRect);

    void displayTexture();
    void handleEvents();
    void setGameState(GameState p_GameState) { _gameState = p_GameState; }

    int getWindowWidth();
    int getWindowHeight();

   private:
    void init(const char *title, int x, int y, int w, int h, Uint32 flags);

    SDL_Window *_window;
    SDL_Renderer *_renderer;

    int _screenWidth;
    int _screenHeight;

    GameState _gameState;
};
