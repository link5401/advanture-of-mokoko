#include "../include/headers/main.h"


int main(int argc, char* argv[]) {
    while (game.getGameState() != GameState::EXIT) {
        game.clear();
        SDL_Rect bgRect = screenScroll(mokoko0, background);
        game.renderBackground(background);
        game.renderTexture(mokoko0, bgRect);
        game.renderTexture(mokoko1, bgRect);
        for (std::vector<Entity> vec1d : platformVector2d) {
            for (Entity e : vec1d) game.renderTexture(e, bgRect);
        }
        game.displayTexture();
        update();
    }

    return 0;
}