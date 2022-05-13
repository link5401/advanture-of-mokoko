#pragma once
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
#include <headers/Math.h>

class Entity{
    public:
        Entity(Vector2f p_pos, int scale, SDL_Texture* p_tex);
        Entity();
        ~Entity();
        int getScale();
        Vector2f& getPos(){
            return pos;
        }
        SDL_Texture* getTexture();
        SDL_Rect getCurrentFrame();

        void operator = (const Entity& E){
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