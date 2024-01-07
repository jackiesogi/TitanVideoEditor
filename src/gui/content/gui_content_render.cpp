#include "gui/render_util.hpp"
#include "editor/editor.hpp"
#include "gui/gui_layout.hpp"
#include "main.hpp"
#include "gui/lib/icons.hpp"
#include "history.hpp"
#include <iostream>


//#include"gui_content_properties.cpp"


//PropertiesMode aproperties_mode = PROPMODE_NONE_SELECTED;


extern int properties_scroll;
extern PropertiesMode properties_mode;
//extern void myFunction();
extern void properties_change_mode(PropertiesMode mode);
extern PropertiesMode properties_current_mode();

enum RenderMode{
Render_HOMEPAGE,
Render_render

};

RenderMode rendermode=Render_HOMEPAGE;

// std::stack<GuiLayoutSplitter> undostk; 

// extern bool saveflag;


void gui_render_homepage(SDL_Renderer* renderer, int x, int y, int w, int h)
{

    button_tooltip("render");
    if (button_icon(renderer, icon_render, x + 4+10, y + 4+10,40,40, 0x404040FF)) 
    {
        rendermode=Render_render;
    }

    button_tooltip("save");
    if (button_icon(renderer, icon_save, x + 4+10+30+ 20, y + 4+10,40,40, 0x404040FF)) 
    {
        //saveflag=true;

        //  for(int i=0;i<sizeof(gui_splitters)/sizeof(GuiLayoutSplitter);i++)
        //  undostk.push(gui_splitters[i]);
        //undostk.push(grabbedSplitter);

        // std::cout<<*(undostk.top().valueMin)<<"\n";
        // std::cout<<*(undostk.top().valueMax)<<"\n";
        // std::cout<<*(undostk.top().extendMin)<<"\n";
        // std::cout<<*(undostk.top().extendMax)<<"\n";
        // std::cout<<undostk.top().isVertical<<"\n";
        // std::cout<<saveflag<<"\n";
    }

    button_tooltip("redo");
    
    if (button_icon(renderer, icon_redo, x + 4+10+20+ 20 +40+ 20, y + 4+10,40,40, 0x404040FF)) 
    {
        redo();
        for (int i = 0; i < sizeof(gui_splitters) / sizeof(GuiLayoutSplitter); i++) 
        {
            GuiLayoutSplitter splitter = gui_splitters[i];
            *splitter.pos = get_current_state()[i];
        }
    }
    button_tooltip("undo");
    
    if (button_icon(renderer, icon_undo, x + 4+10+20+ 20 +40+ 20 +40 +20, y + 4+10,40,40, 0x404040FF)) 
    {
        undo();
        for (int i = 0; i < sizeof(gui_splitters) / sizeof(GuiLayoutSplitter); i++) 
        {
            GuiLayoutSplitter splitter = gui_splitters[i];
            *splitter.pos = get_current_state()[i];
        }
    }
    
    button_tooltip("Exit");
    if (button_icon(renderer, icon_exit, x + 4+10+20+ 20 +40+ 20 +40 +20+50, y + 4+10,40,40, 0x404040FF)) 
    {
        if(saveflag)
        {
            std::cout<<"ok bye~\n";
        }
        else
        {
            //zenity
            //popup window

        }


    }



}

void gui_render_render(SDL_Renderer* renderer, int x, int y, int w, int h)
{

    button_tooltip("return");
    if (button_icon(renderer, icon_return, x + 4+10, y + 4+10,40,40, 0x404040FF)) 
    {
        rendermode=Render_HOMEPAGE;
    }

    button_tooltip("muteaudio");
    if (button_icon(renderer, icon_mute, x + 4+10+50, y + 4+10,40,40, 0x404040FF)) 
    {
        
    }

    button_tooltip("Set Speed");
    if (button_icon(renderer,icon_setspeed, x + 4+10+50+50, y + 4+10,40,40, 0x404040FF)) 
    {
        
    }

    button_tooltip("ExtractFrame");
    if (button_icon(renderer,icon_extractFrame, x + 4+10+50+50, y + 4+10,40,40, 0x404040FF)) 
    {
        
    }


    button_tooltip("concat");
    if (button_icon(renderer,icon_concat, x + 4+10+50+50+50, y + 4+10,40,40, 0x404040FF)) 
    {
        
    }

    button_tooltip("setfilename");
    if (button_icon(renderer,icon_setfilename, x + 4+10+50+50+50, y + 4+10+50,40,40, 0x404040FF)) 
    {
        
    }

}            



void gui_content_render(SDL_Renderer* renderer, int x, int y, int w, int h) 
{


    switch (rendermode) {
        case Render_HOMEPAGE:
            gui_render_homepage(renderer,x,y,w,h);
            break;
        case Render_render:
            gui_render_render(renderer,x,y,w,h);
            button_tooltip("return");
            if (button_icon(renderer, icon_return, x + 4+10, y + 4+10,40,40, 0x404040FF)) 
            {
                rendermode=Render_HOMEPAGE;
            }
            break;
        default:
            rendermode=Render_HOMEPAGE;
            break;
    
    }


}



