#pragma once
#include <headers/Entity.hpp>
#include <vector>
class Mokoko : public Entity
{
public:
    Mokoko(Vector2f p_pos, Vector2f resolution, SDL_Texture *p_tex);
    ~Mokoko();

    void update(double deltaTime);
    void setVelocity(Vector2f p_velo);

private:
    Vector2f Velocity;
    Vector2f Accelaration;
    bool inAir;
    void VelocityHandle(const Uint8 *keyBoardBools);
};