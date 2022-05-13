#include <headers/tileMap.h>
#include <iostream>
tileMap::~tileMap(){}
#define BLOCK_WIDTH 40
#define BASE_HEIGHT 680
/* Loading the map. */
/**
 * It takes a 2D vector of integers and a texture pointer, and creates a 2D vector of Entity objects.
 * 
 * @param vector map_sample
 * @param p_grass a pointer to a texture
 */
tileMap::tileMap(std::vector<std::vector<int>> map_sample, SDL_Texture* p_grass){
/* Copying the 2D vector of integers into another 2D vector of integers. */
    for(std::vector<int> map1d : map_sample) {
        std::vector<int> temp = {};
        for(int tile : map1d) {  
            temp.push_back(tile);  
        }
        int_map.push_back(temp);
        temp.clear();
    }    

  /* Creating a 2D vector of Entity objects. */
    std::vector<Entity> vE = {};
    for(int i = 0; i < int_map.size(); i++){  
        for(int j = 0; j < int_map[i].size(); j++) {
            switch(int_map[i][j]){
                case 0:
                    vE.push_back(Entity(Vector2f(j*BLOCK_WIDTH, 
                                        BASE_HEIGHT+i*BLOCK_WIDTH), 1, p_grass));
                    break;
                default:
                    break;
            }
        }
        actual_map.push_back(vE);
        vE.clear();
    }
}

/**
 * It returns a vector of vectors of Entity objects
 * 
 * @return A vector of vectors of Entity objects.
 */
std::vector<std::vector<Entity>> tileMap::getActualMap(){
    return actual_map;
}