#include<headers/game.h>
int main(int argc, char* argv[]){
    Game game;
    game.run();
    SDL_Texture* mokoko_guy = game.loadTexture("res/images/mokoko-guy.png");
    while (game.getGameState() != GameState::EXIT) {       
        game.renderTexture(mokoko_guy);
        game.handleEvents();
    }

 
    
    return 0;
}