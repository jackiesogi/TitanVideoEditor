#include "helper.hpp"
SDL_Window   	*Window    = NULL;
SDL_Renderer 	*Renderer  = NULL;
TTF_Font  	*icon_font = NULL;

void init(void)
{
SDL_Init(SDL_INIT_EVERYTHING);
TTF_Init();
Window = SDL_CreateWindow("", 0, 0, 0, 0, SDL_WINDOW_HIDDEN);

//BEGIN ICON
//get Android Symbol from font awesome (0xf17b)
SDL_Surface *icon;
icon_font=TTF_OpenFont("./fontawesome-webfont.ttf", 50);
SDL_Color font_color_icon = {255,255,255,255};
icon=TTF_RenderGlyph_Blended(icon_font, 0xf17b , font_color_icon);
SDL_SetWindowIcon(Window, icon);
SDL_FreeSurface(icon);
TTF_CloseFont(icon_font);
//BEGIN ICON
Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

}

void exit_(void)
{

SDL_DestroyRenderer(Renderer);
SDL_DestroyWindow(Window);
TTF_Quit();
SDL_Quit();

}