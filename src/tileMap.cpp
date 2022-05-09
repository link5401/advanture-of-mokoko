#include <headers/tileMap.h>
#include <iostream>
tileMap::~tileMap(){}

/* Loading the map. */
tileMap::tileMap(std::vector<std::vector<int>> map_sample, SDL_Texture* p_grass){
    for(std::vector<int> map1d : map_sample) {
        std::vector<int> temp = {};
        for(int tile : map1d) {  
            temp.push_back(tile);  
        }
        int_map.push_back(temp);
        temp.clear();
    }    

    std::vector<Entity> vE = {};
    for(int i = 0; i < int_map.size(); i++){  
        for(int j = 0; j < int_map[i].size(); j++) {
            vE.push_back(Entity(j*40, 680+i*40, 1, p_grass));
       
        }
        actual_map.push_back(vE);
        vE.clear();
    }

    
}

std::vector<std::vector<Entity>> tileMap::getActualMap(){
    return actual_map;
}