#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
#include <sdl2/SDL_render.h>

#include <headers/Entity.hpp>
#include <headers/Character.hpp>
#include <headers/game.hpp>
#include <vector>

Game game;
int screenWidth = game.getWindowWidth();
int screenHeight = game.getWindowHeight();

/* SDL_Texture  */
SDL_Texture* smol_Character_guy =
    game.loadTexture("res/images/character.png");
SDL_Texture* big_Character_guy = game.loadTexture("res/images/mokoko-guy.png");
SDL_Texture* platform = game.loadTexture("res/images/platform.png");
SDL_Texture* bg = game.loadTexture("res/images/bg4800.png");

/* Entities */
Character Character0(Vector2f(512, 400), Vector2f(500, 500), smol_Character_guy);
Character Character1(Vector2f(1000, 400), Vector2f(72, 72), smol_Character_guy);
Entity background(Vector2f(0, 0), Vector2f(1280, 960), bg);
/*maps */
std::vector<std::vector<int>> test_map = {{0, 0, 0, 0, 0, 0, 0, 0},
                                          {0, 0, 0, 0, 0}};
tileMap map0(test_map, platform);
std::vector<std::vector<Entity>> platformVector2d = map0.getActualMap();

int levelWidth = 4800;
int levelHeight = 2000;


Uint64 currentTick = SDL_GetPerformanceCounter();
Uint64 lastTick = 0;
double deltaTime = 0;
SDL_Event evnt;

void update();
SDL_Rect screenScroll(Character& player, Entity& background);
