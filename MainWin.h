#ifndef MAINWIN_H
#define MAINWIN_H

#include<gtkmm/window.h>
#include<gtkmm/main.h>
#include<gtkmm/fixed.h>
#include<gtkmm/label.h>
#include<gtkmm/builder.h>
#include<gtkmm/entry.h>
#include<gtkmm/combobox.h>
#include<gtkmm/liststore.h>
#include<gtkmm/treemodel.h>

#include<gtkmm/scrolledwindow.h>
#include<gtkmm/textview.h>
#include<gtkmm/menubar.h>
#include<gtkmm/imagemenuitem.h>
#include<gtkmm/menuitem.h>
#include<gtkmm/menu.h>

#include<gtkmm/box.h>

#include<gtkmm/toolbar.h>
#include<gtkmm/toolbutton.h>

#include<gtkmm/drawingarea.h>
#include<gtkmm/filechooserdialog.h>

// #include <mpv/client.h>
// #include <mpv/opengl_cb.h>
// #include <mpv/qthelper.hpp>
// #include <mpv/stream_cb.h>

#include<iostream>




class MainWin : public Gtk::Window
{
protected:
    Gtk::Fixed *fixed;
    Glib::RefPtr<Gtk::Builder> builder;

/**MENUBAR**/
    Gtk::MenuBar *menubar;
    //filemenu
    Gtk::MenuItem *filemenuitem;
    Gtk::Menu *filemenu;
    Gtk::MenuItem *SaveWorkPlace,*ImportVideo,*ExtractAudio,*ExtractFrame,*ExtractClip,*Quit;
    //toolmenu
    Gtk::MenuItem *toolmenuitem;
    Gtk::Menu *toolmenu;
    Gtk::MenuItem *MuteAudio,*SetVol,*SetSpeed,*SetRes,*GetFilename,*SetFilename;
    //playmenu
    Gtk::MenuItem *playmenuitem;
    Gtk::Menu *playmenu;
    Gtk::MenuItem *Play;
    //clipmenu
    Gtk::MenuItem *clipmenuitem;
    Gtk::Menu *clipmenu;
    Gtk::MenuItem *SplitVideo,*OverlaySub,*OverlayAudio,*ConvertVideo,*OmitClip,*Concat,*GetGif;

    Gtk::Label *statelebel;

    Gtk::ScrolledWindow *scrolledwindow;
    //Gtk::ViewPort *scrollviewport;
    Gtk::TextView *textview;
     
/**TOOLBAR**/
    Gtk::Toolbar *toolbar;
    Gtk::ToolButton *playbtn,*savebtn,*openbtn;

/**Video Area**/
    Gtk::DrawingArea *videoarea;
    //mpv_handle* mpv_handle;
public:
    MainWin(BaseObjectType* cobject,const Glib::RefPtr<Gtk::Builder> & refGlade);
    ~MainWin();

protected:

    //filemenu
    void on_SaveWorkPlace_activate();
    void on_ImportVideo_activate();
    void on_ExtractAudio_activate();
    void on_ExtractFrame_activate();
    void on_ExtractClip_activate();
    void on_Quit_activate();
    //toolmenu
    void on_MuteAudio_activate();
    void on_SetVol_activate();
    void on_SetSpeed_activate();
    void on_SetRes_activate();
    void on_GetFilename_activate();
    void on_SetFilename_activate();
    //playmenu
    void on_Play_activate();
    //clipmenu
    void on_SplitVideo_activate();
    void on_OverlaySub_activate();
    void on_OverlayAudio_activate();
    void on_ConvertVideo_activate();
    void on_OmitClip_activate();
    void on_Concat_activate();
    void on_GetGif_activate();
    
    //void play_video(const std::string& ) ;
   // static void on_update(void* );


};






#endif