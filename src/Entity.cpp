#include <headers/Entity.h>
Entity::~Entity() {};

Entity::Entity(float p_x, float p_y, int p_scale, SDL_Texture* p_tex)
 : x(p_x), y(p_y), scale(p_scale), tex(p_tex) 
 {
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 40;
    currentFrame.h = 40;
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
float Entity::getX(){
    return x;
}
float Entity::getY(){
    return y;
}