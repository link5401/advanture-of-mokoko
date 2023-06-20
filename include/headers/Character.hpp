#pragma once
#include <headers/Entity.hpp>
#include <vector>

#define AKey SDL_SCANCODE_A
#define DKey SDL_SCANCODE_D
#define SKey SDL_SCANCODE_S
#define WKey SDL_SCANCODE_W
#define SPACEBAR SDL_SCANCODE_SPACE

#define CHARACTER_WIDTH 85
#define CHARACTER_HEIGHT 115
#define SPRITE_HORIZONTAL 120
#define SPRITE_VERTICAL 130

#define SPRITE_NO 3
#define UP_SPRITE_NO 1
#define MOVING_SPRITE_NO 10

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
    void movementHandle(const Uint8 *p_keyBoardBools);
};