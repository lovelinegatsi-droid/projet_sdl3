#include <SDL3/SDL.h>
#include <iostream>

struct blueSquare{
    int x;
    int y;
};
int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("projet : fenetre sdl3",800, 600, 0);
    if (window == nullptr) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* rendu = SDL_CreateRenderer(window, NULL);
    if (rendu == nullptr) {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Event e;
    bool quit = false;

    // pour mettre le point 
    SDL_FRect blueSquare {400, 300, 50, 50}; // le principe repose sur la position du point: pour le placer au centre, on divise la longueur et la largeur par deux , les autres representent la grosseur du point
    const int vitesse = 10;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            
            } else if (e.type == SDL_EVENT_KEY_DOWN){
                switch (e.key.scancode){
                    case SDL_SCANCODE_UP:
                        blueSquare.y -= vitesse;
                        break;
                    case SDL_SCANCODE_DOWN:
                    blueSquare.y+=vitesse;
                    break;
                    case SDL_SCANCODE_LEFT:
                        blueSquare.x -= vitesse;
                        break;
                    case SDL_SCANCODE_RIGHT:
                        blueSquare.x += vitesse;
                        break;
                    case SDL_SCANCODE_ESCAPE:
                        quit = true;
                    break;

                }
            }
        }

        SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255); // pour mettre la case en noir
        SDL_RenderClear(rendu); // pour effacer le renderer

        SDL_SetRenderDrawColor(rendu, 0, 255, 255, 0); // pour mettre le rendu en couleur bleu le principe va de (rendu, eclairage, couleur, couleur)
        SDL_RenderFillRect(rendu, &blueSquare); // le rendu doit etre un carre
        
        SDL_RenderPresent(rendu); // pour le presenter a l'ecran
    }

    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}