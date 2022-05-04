#include <headers/game.h>
#include <headers/Entity.h>
#include <vector>

#define PLATFORM_WIDTH 40

int main(int argc, char* argv[]){
    Game game;

    int screenWidth = game.getWindowWidth();
    int screenHeight = game.getWindowHeight();

    game.run();
    
    /* SDL_Texture  */
    SDL_Texture* smol_mokoko_guy = game.loadTexture("res/images/mokoko-guy-72x72.png");
    SDL_Texture* big_mokoko_guy = game.loadTexture("res/images/mokoko-guy.png");
    SDL_Texture* platform = game.loadTexture("res/images/platform.png");

    /* Entities */
    Entity mokoko0(100, 100, 3,  smol_mokoko_guy);
    Entity mokoko1(500, 100, 10, big_mokoko_guy);

    /* Vectors */
    std::vector<Entity> platformVector;

    /* Calculating the number of platforms that will fit in the window. */
    const int NUMBER_OF_PLATFORM = (screenWidth / PLATFORM_WIDTH);
    

     /* Creating new platform Entities and pushing them into the vector. */
    for (int i = 0; i <= NUMBER_OF_PLATFORM; i++)
        platformVector.push_back(Entity(PLATFORM_WIDTH*i, 500, 1, platform));

    while (game.getGameState() != GameState::EXIT) {  
        game.clear();  
        
        /*Rendering Texure*/
        game.renderTexture(mokoko0);
        game.renderTexture(mokoko1);
        for (Entity& s : platformVector){
            game.renderTexture(s);
        }

        game.handleEvents();

        game.displayTexture();
    }

 
    
    return 0;
}