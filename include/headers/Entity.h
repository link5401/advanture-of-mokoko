#pragma once
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>

class Entity{
    public:
        Entity(float x, float y, int scale, SDL_Texture* p_tex);
        ~Entity();
        int getScale();
        float getX();
        float getY();
        SDL_Texture* getTexture();
        SDL_Rect getCurrentFrame();
    private:
        int scale;
        float x,y;
        SDL_Rect currentFrame;
        SDL_Texture* tex;
};