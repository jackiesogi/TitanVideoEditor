#include "gui/render_util.hpp"
#include "editor/editor.hpp"
#include "gui/gui_layout.hpp"
#include "main.hpp"
#include "gui/lib/icons.hpp"

#include <iostream>

enum PlayMode{
PLAYMODE_play,
PLAYMODE_pause

};

PlayMode playmode=PLAYMODE_play;

void gui_content_player_utils(SDL_Renderer* renderer, int x, int y, int w, int h) 
{
    

    switch(playmode)
    {
        case PLAYMODE_play:
        button_tooltip("play");
        if (button_icon(renderer, icon_play, x + 4+50+100, y + 4,30,30, 0x404040FF)) 
        {
            std::cout<<"play\n";

            system("ffplay /home/ethan/Downloads/food1.mp4");

            playmode=PLAYMODE_pause;
        }
        //mode=PLAYMODE_pause;
        break;

        case PLAYMODE_pause:
         button_tooltip("puase");
        if (button_icon(renderer, icon_pause, x + 4+50+100, y + 4,30,30, 0x404040FF)) 
        {
            std::cout<<"pause\n";
            
            playmode=PLAYMODE_play;
        }
        // mode=PLAYMODE_play;
            
        break;

        default:
        playmode=PLAYMODE_play;

    }
    // button_tooltip("play");
    // if (button_icon(renderer, icon_play, x + 4+50+100, y + 4,30,30, 0x404040FF)) 
    // {
     
    // }
    
    // button_tooltip("puase");
    // if (button_icon(renderer, icon_pause, x + 4, y + 4,30,30, 0x404040FF)) 
    // {
     
    // }


}