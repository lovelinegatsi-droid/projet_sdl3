#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
//#include <SDL3_image/ SDL3_image.h>

#define WINDOW_TITLE "FENETRE"
#define WINDOW_HEIGHT 800
#define WINDOW_WEIGHT 600

int main(){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_window* Window = nullptr;
    SDL_renderer* renderer = nullptr;
    bool running ;

    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "erreur d'initialisation :" << SDL_GetError() << std::endl ;
        return 1 ;
    } // pour activer les fonctions pouvant gerer les contenues visuels, audio, graphic et autreS
    
    if(!SDL_CreateWindowAndRenderer("SDL3 keyboard" , 800 , 600, 0, &window , &renderer)){
        SDL_Log("ERREUR de creation de fenetre ou de rendu (window/ renderer)", SDL_GetError() ) ;
        return SDL_APP_FAILURE ;
    } else {
        SDL_Color black = {0, 0, 0};
        SDL_Surface *surface = TTF_RenderText_Blended(font, text.c_str(), text.size(), black);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    }
    TIF_Font * font = TIF_OpenFont("FreeSans.ttf", 24) ;// changer la police 
    if(!font) {
        SDL_Log("erreur sur le telechargement de font", SDL_GetError()) ;
        return 1;
    }
    case SDL_EVENT_KEY_DOWN : // pour fermer l'application lorsque l'utilisateur appuie sur echap
    if (EVENT.key.key == SDLK_ESCAPE){
        running = false ;
        break ;
    }

    case SDL_EVENT_TEXT_INPUT:
    text = text + event.text.text;
    break;
}

case SDL_EVENT_KEY_DOWN:
    if (event.key.key == SDLK_BACKSPACE && text.size() > 0) {
        text.pop_back();
    }
break;

float texW = 0, texH = 0;
SDL_GetTextureSize(texture, &texW, &texH);
