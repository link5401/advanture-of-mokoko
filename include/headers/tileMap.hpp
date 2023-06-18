#pragma once
#include <vector>
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
#include <headers/Entity.hpp>


class tileMap{
    public:
        tileMap(std::vector<std::vector<int>> map_sample, SDL_Texture* p_grass);
        ~tileMap();
        std::vector<std::vector<Entity>> getActualMap();
    private:
        std::vector<std::vector<int>> int_map;
        std::vector<std::vector<Entity>> actual_map;
                 
};