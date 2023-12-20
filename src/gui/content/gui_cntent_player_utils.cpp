#include "gui/render_util.hpp"
#include "editor/editor.hpp"
#include "gui/gui_layout.hpp"
#include "main.hpp"
#include "gui/lib/icons.hpp"

#include <iostream>

void gui_content_player_utils(SDL_Renderer* renderer, int x, int y, int w, int h) 
{
    
    button_tooltip("play");
    if (button_icon(renderer, icon_play, x + 4+50+100, y + 4,30,30, 0x404040FF)) 
    {
     
    }
    
    button_tooltip("puase");
    if (button_icon(renderer, icon_pause, x + 4, y + 4,30,30, 0x404040FF)) 
    {
     
    }


}