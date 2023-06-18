#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
#include <sdl2/SDL_render.h>

#include <headers/Entity.hpp>
#include <headers/KeyboardHandler.hpp>
#include <headers/Mokoko.hpp>
#include <headers/game.hpp>
#include <vector>

Game game;
int screenWidth = game.getWindowWidth();
int screenHeight = game.getWindowHeight();

/* SDL_Texture  */
SDL_Texture* smol_mokoko_guy =
    game.loadTexture("res/images/mokoko-guy-72x72.png");
SDL_Texture* big_mokoko_guy = game.loadTexture("res/images/mokoko-guy.png");
SDL_Texture* platform = game.loadTexture("res/images/platform.png");
SDL_Texture* bg = game.loadTexture("res/images/bg4800.png");

/* Entities */
Mokoko mokoko0(Vector2f(512, 400), Vector2f(102, 72), smol_mokoko_guy);
Mokoko mokoko1(Vector2f(1000, 400), Vector2f(72, 72), smol_mokoko_guy);
Entity background(Vector2f(0, 0), Vector2f(1280, 960), bg);
/*maps */
std::vector<std::vector<int>> test_map = {{0, 0, 0, 0, 0, 0, 0, 0},
                                          {0, 0, 0, 0, 0}};
tileMap map0(test_map, platform);
std::vector<std::vector<Entity>> platformVector2d = map0.getActualMap();

/**
 * Update the deltaTime variable with the time difference between the current
 * and last frame.
 */
Uint64 currentTick = SDL_GetPerformanceCounter();
Uint64 lastTick = 0;
double deltaTime = 0;
SDL_Event evnt;
void update() {
    lastTick = currentTick;
    currentTick = SDL_GetPerformanceCounter();
    deltaTime = (double)((currentTick - lastTick) * 1000 /
                         (double)SDL_GetPerformanceFrequency());
    // std::cout << deltaTime << "\n";

    while (SDL_PollEvent(&evnt)) {
        SDL_Scancode _scancode = evnt.key.keysym.scancode;
        switch (evnt.type) {
            case SDL_QUIT:
                game.setGameState(GameState::EXIT);
                break;
            case SDL_KEYDOWN:
                break;
            case SDL_KEYUP:

                break;
        
        }
    }
    mokoko0.update(deltaTime);
}
int levelWidth = 4800;
int levelHeight = 800;
SDL_Rect screenScroll(Mokoko& player, Entity& background) {
    background.setCurrentFramePos(player.getPos().x - (screenWidth / 2),
                                  player.getPos().y - (screenHeight / 2));
    SDL_Rect bgCurrentFrame = background.getCurrentFrame();
    // std::cout << "before:" << background.getCurrentFrame().x << " " <<
    // background.getCurrentFrame().y << "\n";
    if (bgCurrentFrame.x < 0) background.setCurrentFramePosX(0);
    if (bgCurrentFrame.y < 0) background.setCurrentFramePosY(0);
    bgCurrentFrame = background.getCurrentFrame();
    if (bgCurrentFrame.x + bgCurrentFrame.w >= levelWidth)
        background.setCurrentFramePosX(levelWidth - screenWidth);
    if (bgCurrentFrame.y + bgCurrentFrame.h >= levelHeight)
        background.setCurrentFramePosY(levelHeight - screenHeight);
    // std::cout << "after:" << background.getCurrentFrame().x << " " <<
    // background.getCurrentFrame().y << "\n";

    return background.getCurrentFrame();
}