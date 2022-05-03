#include <headers/game.h>

Game::Game() {
    _window = nullptr;
    _renderer = nullptr;
    _screenWidth = 1024;
    _screenHeight = 600;
    _gameState = GameState::PLAY;
};

Game::~Game() {};


void Game::run() {
    init("GAME v1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_SHOWN);
   
}

/**
 * It initializes SDL and creates a window and renderer
 * 
 * @param title The title of the window
 * @param x The x position of the window
 * @param y The y-coordinate of the window, in pixels. This is the initial position of the window on
 * the y-axis.
 * @param w width of the window
 * @param h height
 * @param flags 
 */
void Game::init(const char* title, int x, int y, int w, int h, Uint32 flags){
    
    SDL_Init(SDL_INIT_EVERYTHING);

    _window = SDL_CreateWindow(title, x, y, w, h, flags);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

}

/**
 * It takes a file path to an image, loads the image into a texture, and returns the texture
 * 
 * @param p_filePath The path to the image file.
 * 
 * @return A pointer to a texture.
 */
SDL_Texture* Game::loadTexture(const char* p_filePath){
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(_renderer, p_filePath);
    
    if (texture == NULL){
        std::cout << "Failed to load texture. Error:" << SDL_GetError() << "\n";
    }

    return texture;
}


/**
 * It clears the screen, copies the texture to the renderer, and then displays the texture
 * 
 * @param p_tex The texture to render
 */
void Game::renderTexture(SDL_Texture* p_tex){
    clear();
    SDL_RenderCopy(_renderer, p_tex, NULL, NULL);
    displayTexture();
}
void Game::clear(){
    SDL_RenderClear(_renderer);
}
void Game::displayTexture(){
    SDL_RenderPresent(_renderer);
}

/**
 * It checks if the user has pressed the X button on the window, and if so, it sets the game state to
 * EXIT
 */
void Game::handleEvents() {
    SDL_Event evnt;
    SDL_PollEvent(&evnt);

    switch (evnt.type) {
        case SDL_QUIT:
            _gameState = GameState::EXIT;
            break;
    }    
}