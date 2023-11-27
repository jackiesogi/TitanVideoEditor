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
#include<iostream>




class MainWin : public Gtk::Window
{
protected:
    Gtk::Fixed *fixed;
    Glib::RefPtr<Gtk::Builder> builder;

    Gtk::MenuBar *menubar;
    Gtk::MenuItem *filemenuitem;
    Gtk::Menu *filemenu;
    Gtk::MenuItem *SaveWorkPlace,*ImportVideo,*ExtractAudio,*ExtractFrame,*ExtractClip,*Quit;

    Gtk::Label *statelebel;

    Gtk::ScrolledWindow *scrolledwindow;
    //Gtk::ViewPort *scrollviewport;
    Gtk::TextView *textview;
     
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
};






#endif