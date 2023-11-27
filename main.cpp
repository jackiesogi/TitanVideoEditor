#include <cstdlib>
#include <iostream>
#include <string>
#include "Engine/action.h"
#include <gtkmm.h>
#include "MainWin.h"
/*
class MyWindow : public Gtk::Window
{
public:
    std::string filePath;

    MyWindow() {
        // Set the title of the window
        this->set_title("Simpledit Video Editor");
        this->set_default_size(800, 400);

        // Create a button for selecting a video file
        this->selectButton.set_label("Select Video");
        this->selectButton.set_border_width(50);
        this->selectButton.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_select_button_clicked));
        // Create a button for rendering the output
        this->renderButton.set_label("Render");
        this->renderButton.set_border_width(50);
        this->renderButton.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_render_button_clicked));


        this->convertButton.set_label("ConvertVideo");
        this->convertButton.set_border_width(50);
        this->convertButton.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_convert_button_clicked));

        this->getGifButton.set_label("getGif");
        this->getGifButton.set_border_width(50);
        this->getGifButton.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_getGif_button_clicked));
        
        this->concateButton.set_label("Concate");
        this->concateButton.set_border_width(50);
        this->concateButton.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_concate_button_clicked));
        
        this->muteAudioButton.set_label("MuteAudio");
        this->muteAudioButton.set_border_width(50);
        this->muteAudioButton.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_muteAudio_button_clicked));
        
        

 







        //Label
        this->selectedFileLabel.set_label("Selected File: ");
        this->outputFileLabel.set_label("Output File: ");
        this->convertLabel.set_label("convert File: ");
        this->getGifLabel.set_label("get Gif from :");
        this->concateLabel.set_label("concate:");
        this->muteAudioLabel.set_label("mute audio:");
        
        // Create a vertical box to arrange the widgets
        this->vbox = Gtk::manage(new Gtk::VBox);
        this->vbox->pack_start(this->selectButton, Gtk::PACK_SHRINK);
        this->vbox->pack_start(this->selectedFileLabel, Gtk::PACK_SHRINK);
        this->vbox->pack_start(this->renderButton, Gtk::PACK_SHRINK);
        this->vbox->pack_start(this->outputFileLabel, Gtk::PACK_SHRINK);
        this->vbox->pack_start(this->convertButton, Gtk::PACK_SHRINK);
        this->vbox->pack_start(this->convertLabel, Gtk::PACK_SHRINK);
        this->vbox->pack_start(this->getGifButton, Gtk::PACK_SHRINK);
        this->vbox->pack_start(this->getGifLabel, Gtk::PACK_SHRINK);
        this->vbox->pack_start(this->concateButton, Gtk::PACK_SHRINK);
        this->vbox->pack_start(this->concateLabel, Gtk::PACK_SHRINK);
        this->vbox->pack_start(this->muteAudioButton, Gtk::PACK_SHRINK);
        this->vbox->pack_start(this->muteAudioLabel, Gtk::PACK_SHRINK);



        // Add the vbox to the window
        this->add(*vbox);
    }

    void on_select_button_clicked() {
        Gtk::FileChooserDialog fileDialog("Select a video file", Gtk::FILE_CHOOSER_ACTION_OPEN);
        fileDialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
        fileDialog.add_button("_Open", Gtk::RESPONSE_OK);

        // Add filters to the file dialog if necessary (e.g., filter for video files)
        Glib::RefPtr<Gtk::FileFilter> filter = Gtk::FileFilter::create();
        filter->set_name("Video Files");
        filter->add_mime_type("video/*");
        fileDialog.add_filter(filter);

        int result = fileDialog.run();
        if (result == Gtk::RESPONSE_OK) {
            // User selected a file
            filePath = fileDialog.get_filename();
            // Handle the selected file (e.g., pass it to your video editor)

            // Update the label with the selected file directory
            this->selectedFileLabel.set_label("Selected File: " + filePath);
        }
    }

    void on_render_button_clicked()
    {
        Action *interface = new Action(filePath);

        std::string outputPath = filePath;
        std::string seekTime = "40";
        std::string duration = "20";

        // Find the position of the last dot (.) in the string
        size_t dotPosition = outputPath.find_last_of('.');
    
        // Check if a dot was found and the position is not at the beginning or end of the string
        if (dotPosition != std::string::npos && dotPosition > 0 && dotPosition < outputPath.length() - 1) {
        
            // Replace the substring starting from the dot with ".avi"
            outputPath.replace(dotPosition, outputPath.length() - dotPosition, "_simpledit.mp4");
        
        }
        else
        {        
            // Handle the case where there is no dot or it's at the beginning or end
            std::cerr << "Invalid filePath format" << std::endl;
        }

        interface->extractClip(seekTime, duration, outputPath);
        this->outputFileLabel.set_label("Output File: " + outputPath);
        
        delete interface;
    }

    void on_convert_button_clicked()
    {

        std::cout<<"convert \n";
    }

    void on_getGif_button_clicked()
    {
        std::cout<<"getGif \n";
    }

    void on_concate_button_clicked()
    {
        std::cout<<"concate \n";


    }

    void on_muteAudio_button_clicked()
    {
        std::cout<<"mute Audio \n";
    }

private:
    Gtk::Button selectButton;
    Gtk::Button renderButton;
    Gtk::Button convertButton;
    Gtk::Button getGifButton;
    Gtk::Button concateButton;
    Gtk::Button muteAudioButton; 

    Gtk::Label  selectedFileLabel;
    Gtk::Label  outputFileLabel;
    Gtk::Label convertLabel;
    Gtk::Label getGifLabel;
    Gtk::Label concateLabel;
    Gtk::Label muteAudioLabel;


    Gtk::VBox  *vbox;
};

*/
int main(int argc, char** argv)
{
    Gtk::Main kit(argc, argv);

    //static MyWindow window;
    // MainWin 
    // window.show_all();
    // Gtk::Main::run(window);
    //Gtk::Main kit(argc,argv);
    Glib::RefPtr<Gtk::Builder> builder;

    try 
    {
    builder = Gtk::Builder::create_from_file("MainWin.glade");
    } catch (const Glib::FileError& ex) 
    {
    std::cerr << "File Error: " << ex.what() << std::endl;
    } catch (const Gtk::BuilderError& ex) 
    {
    std::cerr << "Builder Error: " << ex.what() << std::endl;
    } catch (const Glib::Error& ex) 
    {
    std::cerr << "Glib Error: " << ex.what() << std::endl;
    }

    MainWin *mainwin=0;
    builder->get_widget_derived("MainWin",mainwin);

    kit.run(*mainwin);
    return 0;
}
