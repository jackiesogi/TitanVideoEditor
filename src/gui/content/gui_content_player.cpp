#include "gui/render_util.hpp"
#include "editor/editor.hpp"
#include "gui/gui_layout.hpp"
#include "main.hpp"
#include "gui/lib/icons.hpp"

#include <iostream>

void gui_content_player(SDL_Renderer* renderer, int x, int y, int w, int h) 
{
    
    
    //std::string text = std::string(buffer);

    //white rect ,no button
    //render_rect(renderer,10, 0, w, 24, 0x303030FF);
    //render_text(renderer, w - 4 - text.size() * 7, 7, text);
    // button_tooltip("play one");
    // if (button_icon(renderer, icon_play, x + 4, y + 4,32, 32, 0x404040FF)) {
    //     //Track track;
    //     //track.clips = {};
    //    //track.type = TRACKTYPE_VIDEO;
    //     //tracks.push_back(track);
    // }

    button_tooltip("hanni");
    if (button_icon(renderer, icon_hanni, x + 4+10, y + 4+10,200,300, 0x404040FF)) {
        //Track track;
        //track.clips = {};
       //track.type = TRACKTYPE_VIDEO;
        //tracks.push_back(track);
    }



}