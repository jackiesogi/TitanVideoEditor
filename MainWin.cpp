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

    //toolmenu
    builder->get_widget("MuteAudio",MuteAudio);
    builder->get_widget("SetVol",SetVol);
    builder->get_widget("SetSpeed",SetSpeed);
    builder->get_widget("SetRes",SetRes);
    builder->get_widget("GetFilename",GetFilename);
    builder->get_widget("SetFilename",SetFilename);

    MuteAudio->signal_activate().connect(sigc::mem_fun(*this,&MainWin::on_MuteAudio_activate));
    SetVol->signal_activate().connect(sigc::mem_fun(*this,&MainWin::on_SetVol_activate));
    SetSpeed->signal_activate().connect(sigc::mem_fun(*this,&MainWin::on_SetSpeed_activate));
    SetRes->signal_activate().connect(sigc::mem_fun(*this,&MainWin::on_SetRes_activate));
    GetFilename->signal_activate().connect(sigc::mem_fun(*this,&MainWin::on_GetFilename_activate));
    SetFilename->signal_activate().connect(sigc::mem_fun(*this,&MainWin::on_SetFilename_activate));

    //playmenu
    builder->get_widget("Play",Play);
    Play->signal_activate().connect(sigc::mem_fun(*this,&MainWin::on_Play_activate));

    //clipmenu
    builder->get_widget("SplitVideo",SplitVideo);
    builder->get_widget("OverlaySub",OverlaySub);
    builder->get_widget("OverlayAudio",OverlayAudio);
    builder->get_widget("ConvertVideo",ConvertVideo);
    builder->get_widget("OmitClip",OmitClip);
    builder->get_widget("Concat",Concat);
    builder->get_widget("GetGif",GetGif);

    SplitVideo->signal_activate().connect(sigc::mem_fun(*this,&MainWin::on_SplitVideo_activate));
    OverlaySub->signal_activate().connect(sigc::mem_fun(*this,&MainWin::on_OverlaySub_activate));
    OverlayAudio->signal_activate().connect(sigc::mem_fun(*this,&MainWin::on_OverlayAudio_activate));
    ConvertVideo->signal_activate().connect(sigc::mem_fun(*this,&MainWin::on_ConvertVideo_activate));
    OmitClip->signal_activate().connect(sigc::mem_fun(*this,&MainWin::on_OmitClip_activate));
    Concat->signal_activate().connect(sigc::mem_fun(*this,&MainWin::on_Concat_activate));
    GetGif->signal_activate().connect(sigc::mem_fun(*this,&MainWin::on_GetGif_activate));

//toolbar
/*toolbar;
    Gtk::ToolButton *playbtn,*savebtn,*openbtn*/

    builder->get_widget("toolbar",toolbar);
    builder->get_widget("playbtn",playbtn);
    builder->get_widget("savebtn",savebtn);
    builder->get_widget("openbtn",openbtn);

    playbtn->signal_clicked().connect(sigc::mem_fun(*this,&MainWin::on_Play_activate));
    //savebtn
    //openbtn->

    builder->get_widget("scrolledwindow",scrolledwindow);
    //builder->get_widget("scrollviewport",scrollviewport);
    builder->get_widget("textview",textview);

    builder->get_widget("videoarea",videoarea);

    // if (ImportVideo && videoarea) 
    // {
    //   ImportVideo->signal_activate().connect(sigc::mem_fun(*this,&MainWin::on_ImportVideo_activate));

    //   mpv_handle = mpv_create();
    //   if (!mpv_handle) {
    //     throw std::runtime_error("Failed to initialize libmpv.");
    //   }

    //   mpv_set_option_string(mpv_handle, "vo", "opengl-cb");
    //   mpv_set_option_string(mpv_handle, "hwdec", "auto");

    //   mpv_opengl_cb_context* context = mpv_get_sub_api(mpv_handle, MPV_SUB_API_OPENGL_CB);
    //   if (!context) {
    //     throw std::runtime_error("Failed to get libmpv OpenGL context.");
    //   }

    //   mpv_opengl_cb_set_update_callback(context, on_update, this);
    //   mpv_opengl_cb_set_render_param(context, MPV_RENDER_PARAM_API_TYPE, MPV_RENDER_API_TYPE_OPENGL_CB);
    //   mpv_opengl_cb_init_gl(context, NULL, videoarea->get_window()->gobj());

    //   add(*videoarea);
    //   show_all();
    // }


}


MainWin::~MainWin()
{
    // if (mpv_handle) {
    //   mpv_opengl_cb_uninit_gl(mpv_get_sub_api(mpv_handle, MPV_SUB_API_OPENGL_CB));
    //   mpv_terminate_destroy(mpv_handle);
    // }
}

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
    Gtk::FileChooserDialog dialog("Please choose a file", Gtk::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

    // Add response buttons to the dialog:
    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("_Open", Gtk::RESPONSE_OK);

    int result = dialog.run();

    // Handle the response:
    if (result == Gtk::RESPONSE_OK) 
    {
      std::string filename = dialog.get_filename();
    //   play_video(filename);
        statelebel->set_text(filename);
    }

}
// void MainWin::play_video(const std::string& filename) 
// {
//     std::string command = "loadfile " + filename;
//     mpv_command_string(mpv_handle, command.c_str(), NULL);
// }
    
// static void MainWin::on_update(void* ctx) 
// {
//     auto self = static_cast<VideoPlayer*>(ctx);
//     self->video_area->queue_draw();
// }

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

void MainWin::on_MuteAudio_activate()
{
    statelebel->set_text("Mute Audio");
    auto buffer = textview->get_buffer();
    buffer->insert(buffer->end(), "Mute Audio\n");

}

void MainWin::on_SetVol_activate()
{
    statelebel->set_text("Set Volume to");
    auto buffer = textview->get_buffer();
    buffer->insert(buffer->end(), "Set Volume\n");

}

void MainWin::on_SetSpeed_activate()
{
    statelebel->set_text("Set Speed to");
    auto buffer = textview->get_buffer();
    buffer->insert(buffer->end(), "Set Speed\n");
}

void MainWin::on_SetRes_activate()
{
    statelebel->set_text("Set Res");
    auto buffer = textview->get_buffer();
    buffer->insert(buffer->end(), "Set Res\n");

}

void MainWin::on_GetFilename_activate()
{
    statelebel->set_text("Get File name");
    auto buffer = textview->get_buffer();
    buffer->insert(buffer->end(), "Filename is \n");
}

void MainWin::on_SetFilename_activate()
{
    statelebel->set_text("SetFilename");
    auto buffer = textview->get_buffer();
    buffer->insert(buffer->end(), "SetFilename \n");

}

void MainWin::on_Play_activate()
{
    statelebel->set_text("Play");
    auto buffer = textview->get_buffer();
    buffer->insert(buffer->end(), "Play \n");
}

void MainWin::on_SplitVideo_activate()
{
    statelebel->set_text("SplitVideo");
    auto buffer = textview->get_buffer();
    buffer->insert(buffer->end(), "SplitVideo \n");
}
void MainWin::on_OverlaySub_activate()
{
    statelebel->set_text("OverlaySub");
    auto buffer = textview->get_buffer();
    buffer->insert(buffer->end(), "OverlaySub \n");

}
void MainWin::on_OverlayAudio_activate()
{
    statelebel->set_text("OOverlayAudio");
    auto buffer = textview->get_buffer();
    buffer->insert(buffer->end(), "Overlay Audio \n");

}
void MainWin::on_ConvertVideo_activate()
{
    statelebel->set_text("ConvertVideo");
    auto buffer = textview->get_buffer();
    buffer->insert(buffer->end(), "ConvertVideo \n");

}

void MainWin::on_OmitClip_activate()
{
    statelebel->set_text("OmitClip");
    auto buffer = textview->get_buffer();
    buffer->insert(buffer->end(), "OmitClip\n");

}
void MainWin::on_Concat_activate()
{
    statelebel->set_text("Concat");
    auto buffer = textview->get_buffer();
    buffer->insert(buffer->end(), "Concat \n");

}
void MainWin::on_GetGif_activate()
{
    statelebel->set_text("GetGif");
    auto buffer = textview->get_buffer();
    buffer->insert(buffer->end(), "GetGif \n");

}



