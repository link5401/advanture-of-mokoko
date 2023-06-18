#include <headers/Entity.hpp>
Entity::Entity() {};
Entity::~Entity() {};

Entity::Entity(Vector2f p_pos,Vector2f resolution, SDL_Texture* p_tex)
 : pos(p_pos), tex(p_tex) 
 {
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = resolution.x;
    currentFrame.h = resolution.y;
}
SDL_Rect Entity::getCurrentFrame(){
    return currentFrame;
}
SDL_Texture* Entity::getTexture(){
    return tex;
}



