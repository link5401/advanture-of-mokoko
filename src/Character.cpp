#include <headers/Character.hpp>
Vector2f still(0, 0);

Character::Character(Vector2f p_pos, Vector2f resolution, SDL_Texture* p_tex)
    : Entity(p_pos, resolution, p_tex) {
    _Direction = Direction::DOWN;
    Velocity.x = 0;
    Velocity.y = 0;
    Accelaration.x = 1;
    Accelaration.y = 1;
}
Character::~Character() {}
void Character::setVelocity(Vector2f& p_velo){Velocity = p_velo;}
void Character::setMoving(bool _isMoving) {b_isMoving = _isMoving;}
bool Character::isMoving() { return b_isMoving;}
Vector2f Character::getVelocity() { return Velocity;}
Direction Character::getDirection() {return _Direction;}



void Character::movementHandle(const Uint8* _keyState) {
    if (_keyState[AKey]) {
        Velocity.x -= Accelaration.x;
        _Direction = Direction::LEFT;
    }
    if (_keyState[DKey]) {
        Velocity.x += Accelaration.x;
        _Direction = Direction::RIGHT;

    }
    if (_keyState[WKey]) {
        Velocity.y -= Accelaration.y;
        _Direction = Direction::UP;

    }
    if (_keyState[SKey]) {
        Velocity.y += Accelaration.y;
        _Direction = Direction::DOWN;

    }
}

bool checkCollision(float x1, float y1, int w1, int h1, float x2, float y2,
                    int w2, int h2) {
    return (x1 + w1 >= x2) && (x2 + w2 >= x1) && (y1 + h1 >= y2) &&
           (y2 + h2 >= y1);
}

void Character::update(double deltaTime) {
    const Uint8* _keyState = SDL_GetKeyboardState(NULL);
    movementHandle(_keyState);
    Vector2f newPosition = (Velocity * deltaTime) + getPos();
    float x1 = newPosition.x, y1 = newPosition.y;
    if(x1 < 0 || x1 > LEVEL_WIDTH || y1 < 0 || y1 > LEVEL_HEIGHT) newPosition = getPos();
    setPos(newPosition);
    setVelocity(still);
}

// void Character::update(double deltaTime) {
//     Velocity.y += GRAVITY;
//     const Uint8* keyboardBools = SDL_GetKeyboardState(NULL);
//     VelocityHandle(keyboardBools);
//     Vector2f newPosition = (Velocity * deltaTime) + getPos();
//     float x1 = newPosition.x, y1 = newPosition.y;
//     x2 = pE.getPos().x,
//     y2 = pE.getPos().y;
//     int w1 = getCurrentFrame().w, h1 = getCurrentFrame().h;
//     w2 = pE.getCurrentFrame().w,
//     h2 = pE.getCurrentFrame().h;
//     if(!checkCollision(x1,y1,w1,h1,x2,y2,w2,h2)){

//     }
//     setPos(newPosition);

//     if (y1 >= GROUND_LEVEL) {
//         setPos(Vector2f(x1, GROUND_LEVEL));
//         Velocity.y = 0;
//         inAir = false;
//     }
//     setVelocity(still);
//     getPos().print();
// }
