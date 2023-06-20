#include "../include/headers/main.h"

int main(int argc, char* argv[]) {
    while (game.getGameState() != GameState::EXIT) {
        update();

        game.clear();
    }

    return 0;
}

/**
 * The function updates the position of the background entity based on the
 * player's position and returns the current frame of the background to be
 * displayed on the screen.
 *
 * @param player A reference to a Character object, which likely represents the
 * player character in a game.
 * @param background An object of the Entity class representing the background
 * image of the game level.
 *
 * @return The function `screenScroll` returns an `SDL_Rect` object, which
 * represents the current frame of the background entity that is being scrolled
 * based on the position of the player character.
 */
SDL_Rect screenScroll(Character& player, Entity& background) {
    background.setCurrentFramePos(player.getPos().x - (screenWidth / 2),
                                  player.getPos().y - (screenHeight / 2));
    SDL_Rect bgCurrentFrame = background.getCurrentFrame();

    if (bgCurrentFrame.x < 0) background.setCurrentFramePosX(0);
    if (bgCurrentFrame.y < 0) background.setCurrentFramePosY(0);
    bgCurrentFrame = background.getCurrentFrame();
    if (bgCurrentFrame.x + bgCurrentFrame.w >= levelWidth)
        background.setCurrentFramePosX(levelWidth - screenWidth);
    if (bgCurrentFrame.y + bgCurrentFrame.h >= levelHeight)
        background.setCurrentFramePosY(levelHeight - screenHeight);
    return background.getCurrentFrame();
}

void update() {
    while (SDL_PollEvent(&evnt)) {
        SDL_Scancode _scancode = evnt.key.keysym.scancode;
        switch (evnt.type) {
            case SDL_QUIT:
                game.setGameState(GameState::EXIT);
                break;
            case SDL_KEYDOWN:
                Character0.setMoving(true);
                break;
            case SDL_KEYUP:
                Character0.setMoving(false);
                break;
        }
    }

    lastTick = currentTick;
    currentTick = SDL_GetPerformanceCounter();
    deltaTime = (double)((currentTick - lastTick) * 1000 /
                         (double)SDL_GetPerformanceFrequency());
    SDL_Rect bgRect = screenScroll(Character0, background);

    game.renderCharacter(Character0, bgRect);
    // game.renderBackground(background);
    // game.renderTexture(Character1, bgRect);
    for (std::vector<Entity> vec1d : platformVector2d) {
        for (Entity e : vec1d) game.renderTexture(e, bgRect);
    }
    game.displayTexture();

    Character0.update(deltaTime);
}