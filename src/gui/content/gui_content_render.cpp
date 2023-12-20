#include "gui/render_util.hpp"
#include "editor/editor.hpp"
#include "gui/gui_layout.hpp"
#include "main.hpp"
#include "gui/lib/icons.hpp"

#include <iostream>

void gui_content_render(SDL_Renderer* renderer, int x, int y, int w, int h) 
{
    
    button_tooltip("render");
    if (button_icon(renderer, icon_render, x + 4+10, y + 4+10,30,30, 0x404040FF)) 
    {
      render_text(renderer, 100, 7, "render haha");
    }
    //render_text(renderer, 100, 7, "render haha");
    button_tooltip("save");
    if (button_icon(renderer, icon_save, x + 4+10+30+ 20, y + 4+10,40,40, 0x404040FF)) 
    {
      
    }

    button_tooltip("redo");
    if (button_icon(renderer, icon_redo, x + 4+10+20+ 20 +40+ 20, y + 4+10,40,40, 0x404040FF)) 
    {
      
    }

    button_tooltip("undo");
    if (button_icon(renderer, icon_undo, x + 4+10+20+ 20 +40+ 20 +40 +20, y + 4+10,40,40, 0x404040FF)) 
    {
      
    }





    //std::cout<<"render\n";

}