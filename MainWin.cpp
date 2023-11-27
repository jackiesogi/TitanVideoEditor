#include"MainWin.h"

using namespace std;

MainWin::MainWin(BaseObjectType* cobject,const Glib::RefPtr<Gtk::Builder> & refGlade)
: Gtk::Window(cobject),builder(refGlade)
{

    builder->get_widget("fixed",fixed);

    builder->get_widget("statelebel",statelebel);
    //filemenu
    builder->get_widget("SaveWorkPlace",SaveWorkPlace);
    builder->get_widget("ImportVideo",ImportVideo);
    builder->get_widget("ExtractAudio",ExtractAudio);
    builder->get_widget("ExtractFrame",ExtractFrame);
    builder->get_widget("ExtractClip",ExtractClip);
    builder->get_widget("Quit",Quit);


    SaveWorkPlace->signal_activate().connect(sigc::mem_fun(*this,&MainWin::on_SaveWorkPlace_activate));
    ImportVideo->signal_activate().connect(sigc::mem_fun(*this,&MainWin::on_ImportVideo_activate));
    ExtractAudio->signal_activate().connect(sigc::mem_fun(*this,&MainWin::on_ExtractAudio_activate));
    ExtractFrame->signal_activate().connect(sigc::mem_fun(*this,&MainWin::on_ExtractFrame_activate));
    ExtractClip->signal_activate().connect(sigc::mem_fun(*this,&MainWin::on_ExtractClip_activate));
    Quit->signal_activate().connect(sigc::mem_fun(*this,&MainWin::on_Quit_activate));

    builder->get_widget("scrolledwindow",scrolledwindow);
    //builder->get_widget("scrollviewport",scrollviewport);
    builder->get_widget("textview",textview);


}


MainWin::~MainWin()
{}

void MainWin::on_SaveWorkPlace_activate()
{
    statelebel->set_text("SaveWorkPlace");

    auto buffer = textview->get_buffer();
    buffer->insert(buffer->end(), "SaveWorkPlace.\n");
}

void MainWin::on_ImportVideo_activate()
{
    statelebel->set_text("Import Video");
    auto buffer = textview->get_buffer();
    buffer->insert(buffer->end(), "Import Video.\n");

}
    
void MainWin::on_ExtractAudio_activate()
{
    statelebel->set_text("Extract Audio");
    auto buffer = textview->get_buffer();
    buffer->insert(buffer->end(), "Extract Audio\n");
}

void MainWin::on_ExtractFrame_activate()
{
    statelebel->set_text("Extract Frame");
    auto buffer = textview->get_buffer();
    buffer->insert(buffer->end(), "Extract Frame\n");
}

void MainWin::on_ExtractClip_activate()
{
    statelebel->set_text("Extract Clip");
    auto buffer = textview->get_buffer();
    buffer->insert(buffer->end(), "Extract Clip\n");
}

void MainWin::on_Quit_activate()
{
    statelebel->set_text("Quit");
    auto buffer = textview->get_buffer();
    buffer->insert(buffer->end(), "Quit\n");

}