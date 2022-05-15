#include <headers/Entity.h>
Entity::Entity() {};
Entity::~Entity() {};

Entity::Entity(Vector2f p_pos, int p_scale, SDL_Texture* p_tex)
 : pos(p_pos), scale(p_scale), tex(p_tex) 
 {
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = BASE * p_scale;
    currentFrame.h = BASE * p_scale;
}
SDL_Rect Entity::getCurrentFrame(){
    return currentFrame;
}
SDL_Texture* Entity::getTexture(){
    return tex;
}
int Entity::getScale(){
    return scale;
}


