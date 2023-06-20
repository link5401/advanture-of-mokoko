#include <headers/game.hpp>
#include <vector>
Game::Game() {
    _window = nullptr;
    _renderer = nullptr;
    _screenWidth = 1280;
    _screenHeight = 960;
    _gameState = GameState::PLAY;
    init("GAME v1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
         _screenWidth, _screenHeight, SDL_WINDOW_SHOWN);
};

Game::~Game(){
    // SDL_DestroyWindow(_window);
    // SDL_DestroyRenderer(_renderer);
    // _window = nullptr;
    // _renderer = nullptr;
};

/**
 * It initializes SDL and creates a window and renderer
 *
 * @param title The title of the window
 * @param x The x position of the window
 * @param y The y-coordinate of the window, in pixels. This is the initial
 * position of the window on the y-axis.
 * @param w width of the window
 * @param h height
 * @param flags
 */
void Game::init(const char* title, int x, int y, int w, int h, Uint32 flags) {
    SDL_Init(SDL_INIT_EVERYTHING);

    _window = SDL_CreateWindow(title, x, y, w, h, flags);
    _renderer = SDL_CreateRenderer(
        _window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(_renderer, 200, 180, 175, 255);
    SDL_RenderClear(_renderer);
}

/**
 * It takes a file path to an image, loads the image into a texture, and returns
 * the texture
 *
 * @param p_filePath The path to the image file.
 *
 * @return A pointer to a texture.
 */
SDL_Texture* Game::loadTexture(const char* p_filePath) {
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(_renderer, p_filePath);

    if (texture == NULL) {
        std::cout << "Failed to load texture. Error:" << SDL_GetError() << "\n";
    }

    return texture;
}

/**
 * It clears the screen, copies the texture to the renderer, and then displays
 * the texture
 *
 * @param p_tex The texture to render
 */
void Game::renderTexture(Entity& p_Entity, SDL_Rect cameraRect) {
    SDL_Texture* texture = p_Entity.getTexture();
    SDL_Rect currentFrame = p_Entity.getCurrentFrame();

    SDL_Rect src;
    src.x = currentFrame.x;
    src.y = currentFrame.y;
    src.w = currentFrame.w;
    src.h = currentFrame.h;

    SDL_Rect dst;
    dst.x = p_Entity.getPos().x - cameraRect.x;
    dst.y = p_Entity.getPos().y - cameraRect.y;
    dst.w = currentFrame.w;
    dst.h = currentFrame.h;

    /* Copying the texture to the renderer. */
    SDL_RenderCopy(_renderer, texture, &src, &dst);
    // src.x = dst.x;
    // src.y = dst.y;
}
void Game::renderCharacter(Character& p_Character, SDL_Rect cameraRect) {
    SDL_Texture* texture = p_Character.getTexture();
    SDL_Rect currentFrame = p_Character.getCurrentFrame();
    Uint32 characterDirection = (Uint32)p_Character.getDirection();
    Uint32 spriteNumber =
        characterDirection == (Uint32)Direction::UP ? UP_SPRITE_NO : SPRITE_NO;
    Uint32 animationFrequency = 500;

    if (p_Character.isMoving()) {
        characterDirection += 4;
        spriteNumber = MOVING_SPRITE_NO;
        animationFrequency = 50;
    }
    Uint32 sprite = (SDL_GetTicks() / animationFrequency) % spriteNumber;
    SDL_Rect src;
    src.x = sprite * SPRITE_HORIZONTAL;
    src.y = characterDirection * SPRITE_VERTICAL;
    src.w = CHARACTER_WIDTH;
    src.h = CHARACTER_HEIGHT;
    SDL_Rect dst;
    dst.x = p_Character.getPos().x - cameraRect.x;
    dst.y = p_Character.getPos().y - cameraRect.y;
    dst.w = CHARACTER_WIDTH;
    dst.h = CHARACTER_HEIGHT;
    SDL_RenderCopy(_renderer, texture, &src, &dst);
}

void Game::renderBackground(Entity& p_Entity) {
    SDL_Texture* texture = p_Entity.getTexture();
    SDL_Rect currentFrame = p_Entity.getCurrentFrame();

    SDL_Rect src;
    src.x = currentFrame.x;
    src.y = currentFrame.y;
    src.w = currentFrame.w;
    src.h = currentFrame.h;

    /* Copying the texture to the renderer. */
    SDL_RenderCopy(_renderer, texture, &src, NULL);
}
void Game::clear() { SDL_RenderClear(_renderer); }
void Game::displayTexture() { SDL_RenderPresent(_renderer); }

/**
 * It checks if the user has pressed the X button on the window, and if so, it
 * sets the game state to EXIT
 */
void Game::handleEvents() {}

int Game::getWindowHeight() { return _screenHeight; }
int Game::getWindowWidth() { return _screenWidth; }
