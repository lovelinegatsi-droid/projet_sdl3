#include<iostream>
#include<SDL3/SDL.h> // permet d'utiliser toutes les fonctions de sdl(fenetre, rendu, evenements, etc)

int main(int argc, char** argv){
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "erreur d'initialisation :" << SDL_GetError() << std::endl ;
        return 1 ;
    } // pour activer les fonctions pouvant gerer les contenues visuels, audio, graphic et autres
    // creeons une fenetre centree, de longueur 800 et largeur 600 avec une hauteur nulle    
    SDL_Windows* SDL_Window = SDL_CreateWindow(fenetreSDL ,(SDL_WINDOWPOS_CENTERED), SDL_WINDOWPOS_CENTERED, 800, 600, 0 );
   // verifions si la fenetre a bien ete creer
    if(!Window){
        std::cout << "erreur de creation de fenetre" << SDL_GetError() << std::endl;
        SDL_Quit() ; // ca sortira du programme
        return 1 ;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(SDL_Window, -1, SDL_RENDERER_ACCELERATED) ;
    if(!renderer) {
        std::cout<< "erreur de creation de rendu" << SDL_GetError() << std::endl ;
        SDL_DestroyWindow(Window) ;
        SDL_Quit() ;
        return 1;
    }

    SDL_RendererDrawColor(renderer, 0, 0, 0,255); // pour afficher la case en noir qui est le but de la presence des 0,0, 0

    SDL_RenderPresent(renderer) ; // pour generer le rendu

    SDL_Delay(5000) ; // patiente 5 seconde avant de generer

    SDL_DestroyRenderer(renderer) ;
    SDL_DestroyWindow(Window) ;

    SDL_Quit() ;

    return 0;
}