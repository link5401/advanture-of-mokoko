#pragma once
#include <headers/Entity.hpp>
#include <vector>



enum class Direction : Uint32 { DOWN = 0, LEFT = 1, UP = 2, RIGHT = 3 };

class Character : public Entity {
   public:
    Character(Vector2f p_pos, Vector2f resolution, SDL_Texture *p_tex);
    ~Character();

    void update(double deltaTime);
    void setVelocity(Vector2f &p_velo);
    void setMoving(bool _isMoving);

    bool isMoving();
    Vector2f getVelocity();
    Direction getDirection();

   private:
    Direction _Direction;
    Vector2f Velocity;
    Vector2f Accelaration;
    bool b_isMoving;
    void movementHandle(const Uint8* p_keyBoardBools);
};