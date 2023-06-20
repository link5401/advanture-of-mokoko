#pragma once
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
#include <headers/config.hpp>
#include <headers/Math.hpp>

#define BASE 8
class Entity {
   public:
    Entity(Vector2f p_pos, Vector2f resolution, SDL_Texture* p_tex);
    Entity();
    ~Entity();
    Vector2f& getPos() { return pos; }
    SDL_Texture* getTexture();
    SDL_Rect getCurrentFrame();

    void setCurrentFramePosX(int _x) { currentFrame.x = _x; }
    void setCurrentFramePosY(int _y) { currentFrame.y = _y; }
    void setCurrentFramePos(int _x, int _y) {
        currentFrame.x = _x;
        currentFrame.y = _y;
    }
    void setPos(Vector2f p_vect) {
        pos.x = p_vect.x;
        pos.y = p_vect.y;
    }
    void operator=(const Entity& E) {
        scale = E.scale;
        pos = E.pos;
        currentFrame = E.currentFrame;
        tex = E.tex;
    }


   private:
    int scale;
    Vector2f pos;
    SDL_Rect currentFrame;
    SDL_Texture* tex;
};