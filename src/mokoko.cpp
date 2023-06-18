#include <headers/Mokoko.hpp>
#define AKey SDL_SCANCODE_A
#define DKey SDL_SCANCODE_D
#define SKey SDL_SCANCODE_S
#define WKey SDL_SCANCODE_W
#define SPACEBAR SDL_SCANCODE_SPACE

#define GRAVITY 0.8
#define GROUND_LEVEL 600
Mokoko::Mokoko(Vector2f p_pos, Vector2f resolution, SDL_Texture* p_tex)
    : Entity(p_pos, resolution, p_tex) {
    Velocity.x = 0;
    Velocity.y = 0;
    Accelaration.x = 1;
    Accelaration.y = 25;
    inAir = true;
}

Mokoko::~Mokoko() {}

/* Diretional vectors for movement*/

Vector2f still(0, 0);
void Mokoko::setVelocity(Vector2f p_velo) { Velocity = p_velo; }

/**
 * If the player is pressing a key, set the velocity to the direction of the key
 *
 * @param keyboardBools An array of bools that represent the state of the
 * keyboard.
 */

void Mokoko::VelocityHandle(const Uint8* keyboardBools) {
    if (keyboardBools[AKey]) Velocity.x -= Accelaration.x;
    if (keyboardBools[DKey]) Velocity.x += Accelaration.x;
    if (keyboardBools[SPACEBAR] && !inAir) {
        Velocity.y = -Accelaration.y;
        inAir = true;
    }
}

bool checkCollision(float x1, float y1, int w1, int h1, float x2, float y2,
                    int w2, int h2) {
    return (x1 + w1 >= x2) && (x2 + w2 >= x1) && (y1 + h1 >= y2) &&
           (y2 + h2 >= y1);
}

void Mokoko::update(double deltaTime) {
    Velocity.y += GRAVITY;
    const Uint8* keyboardBools = SDL_GetKeyboardState(NULL);
    VelocityHandle(keyboardBools);
    Vector2f newPosition = (Velocity * deltaTime) + getPos();
    float x1 = newPosition.x, y1 = newPosition.y;
    // x2 = pE.getPos().x,
    // y2 = pE.getPos().y;
    // int w1 = getCurrentFrame().w, h1 = getCurrentFrame().h;
    // w2 = pE.getCurrentFrame().w,
    // h2 = pE.getCurrentFrame().h;
    // if(!checkCollision(x1,y1,w1,h1,x2,y2,w2,h2)){

    // }
    setPos(newPosition);

    if (y1 >= GROUND_LEVEL) {
        setPos(Vector2f(x1, GROUND_LEVEL));
        Velocity.y = 0;
        inAir = false;
    }
    setVelocity(still);
    getPos().print();
}