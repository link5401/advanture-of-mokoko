#include <headers/game.h>
#include <headers/Entity.h>
#include <vector>
#define PLATFORM_WIDTH 40

Game game;
int screenWidth = game.getWindowWidth();
int screenHeight = game.getWindowHeight();
/* SDL_Texture  */
SDL_Texture* smol_mokoko_guy = game.loadTexture("res/images/mokoko-guy-72x72.png");
SDL_Texture* big_mokoko_guy = game.loadTexture("res/images/mokoko-guy.png");
SDL_Texture* platform = game.loadTexture("res/images/platform.png");

/* Entities */
Entity mokoko0(Vector2f(100, 100), 3,  smol_mokoko_guy);
Entity mokoko1(Vector2f(500, 100), 10, big_mokoko_guy);

/*maps */
std::vector<std::vector<int>> test_map =
{
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0}
};
tileMap map0(test_map, platform);
std::vector<std::vector<Entity>> platformVector2d = map0.getActualMap();


/**
 * Update the deltaTime variable with the time difference between the current and last frame.
 */
Uint64 currentTick = SDL_GetPerformanceCounter();
Uint64 lastTick = 0;
double deltaTime = 0;
void update(){
    lastTick = currentTick;
    currentTick = SDL_GetPerformanceCounter();
    deltaTime = (double)((currentTick - lastTick)*1000 / (double)SDL_GetPerformanceFrequency());
    std::cout << deltaTime << "\n";
    game.handleEvents();  
}

int main(int argc, char* argv[]){ 
  
    while (game.getGameState() != GameState::EXIT) { 
        game.clear(); 

        game.renderTexture(mokoko0);
        game.renderTexture(mokoko1);
        for(std::vector<Entity> vec1d : platformVector2d){
            for(Entity e : vec1d) game.renderTexture(e);
        }     

        game.displayTexture();  
        update();
    }

    return 0;
}