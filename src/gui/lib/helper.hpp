#ifndef _HELPER_H_
#define _HELPER_H_
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#define WHITE 255, 255, 255, 255
#define BLACK 0, 0, 0, 255
#define RED 255, 0, 0, 255
#define BLUE 0, 0, 255, 255
#define GREEN 0, 255, 0, 255
#define YELLOW 255, 255, 0, 255
#define ORANGE 0, 255, 255, 255
#define CYAN 255, 0, 127, 255
#define DCYAN 255, 127, 0, 255
#define PINK 0, 127, 127,
#define GREY 63, 63, 63, 255
#define LTGREY 191, 191, 191, 255
#define DKBLUE 0, 0, 127, 255
#define DKRED 127, 0, 0, 255
#define DKGREEN 0, 127, 0, 255

extern SDL_Window *Window;
extern SDL_Renderer *Renderer;

void init(void);
void exit_(void);
#endif