## PROJET SDL3 ##

SALUT !!!! BIENVENUE DANS MON PREMIER PROJET REALISER EN SDL3!!!!😎😎😎😎😎😎😎

_Il s'agit ici de realiser un **une surface dans laquelle il y a point qu'on peut diriger avec les touches du clavier **_

Le programme necessite de comprendre certaines base de la progrmmation avec sdl3

#include <SDL3/SDL.h> // cette bibliotheque comporte des fonctions de sdl et gere le graphisme, l'audio et autres 
#include <iostream> // comme toujours celle ci permet de gerer les fonctions d'entree sortie

#### DECLARATION D'UNE STRUCTURE POUR MANIPULER LES POSITIONS ####
struct redSquare{
    int x;   // ELLE gerera la position en abscisse 
    int y;    // gerera la position en ordonnee
}; 

#### PROGRAMME PRINCIPAL ####

** CE programme contiendra toutes les sous fonctions de ces differentes bibliotheques**

##### AFFICHAGE WINDOW #####
_pour activer les fonctions audio, video, image, graphic et autres , on fait ce **SDL_Init**_
    SDL_Init(SDL_INIT_VIDEO);

_la creation de la fenetre window se fait comme suit_

    SDL_Window* window = SDL_CreateWindow("projet : fenetre sdl3",800, 600, 0);
    if (window == nullptr) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

##### RENDU #####

    SDL_Renderer* rendu = SDL_CreateRenderer(window, NULL);
    if (rendu == nullptr) {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }


##### ** MANIPULATION DES DIFFERENTES TOUCHES DU CLAVIER ** #####

    SDL_Event e;
    bool quit = false;

_// pour mettre le point_ 
    SDL_FRect redSquare {400, 300, 50, 50};

_// le principe repose sur la position du point: pour le placer au centre, on divise la longueur et la largeur par deux , les autres representent la grosseur du point_

    const int vitesse = 10;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            
            } else if (e.type == SDL_EVENT_KEY_DOWN){
                switch (e.key.scancode){
                    case SDL_SCANCODE_UP:
                        redSquare.y -= vitesse;
                        break;
                    case SDL_SCANCODE_DOWN:
                        redSquare.y+=vitesse;
                    break;
                    case SDL_SCANCODE_LEFT:
                        redSquare.x -= vitesse;
                        break;
                    case SDL_SCANCODE_RIGHT:
                        redSquare.x += vitesse;
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
        SDL_RenderFillRect(rendu, &redSquare); // le rendu doit etre un carre
        
        SDL_RenderPresent(rendu); // pour le presenter a l'ecran
    }

**NB:** _Cette partie de destroy ne devrait pas manquer_

###### COMPILATION ET EXECUTION #####

_Voici pour la compilation_ 

 clang++ nom_ficher.cpp -o nom_de_lexecutable -lsdl3

_voici pour l'execution_
./nom de l'executable

MERCI 😁😁😁😁 ET A LA PROCHAINE POUR UN NOUVEAU PROGRAMME 😉😉😉😉