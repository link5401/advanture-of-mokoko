#pragma once
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>

class Entity{
    public:
        Entity(float x, float y, int scale, SDL_Texture* p_tex);
        Entity();
        ~Entity();
        int getScale();
        float getX();
        float getY();
        SDL_Texture* getTexture();
        SDL_Rect getCurrentFrame();

        void operator = (const Entity& E){
            scale = E.scale;
            x = E.x;
            y = E.y;
            currentFrame = E.currentFrame;
            tex = E.tex;
        }
    private:
        int scale;
        float x,y;
        SDL_Rect currentFrame;
        SDL_Texture* tex;
};