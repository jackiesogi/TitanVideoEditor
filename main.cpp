#include <cstdlib>
#include <iostream>
#include <gtkmm.h>
#include <string>
#include "Engine/action.h"
#include "gtkmm/box.h"
#include "gtkmm/label.h"

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

        // Create a label for displaying the selected file directory
        this->selectedFileLabel.set_label("Selected File: ");
        // Create a label for displaying the output file directory
        this->outputFileLabel.set_label("Output File: ");
        
        // Create a vertical box to arrange the widgets
        this->vbox = Gtk::manage(new Gtk::VBox);
        this->vbox->pack_start(this->selectButton, Gtk::PACK_SHRINK);
        this->vbox->pack_start(this->selectedFileLabel, Gtk::PACK_SHRINK);
        this->vbox->pack_start(this->renderButton, Gtk::PACK_SHRINK);
        this->vbox->pack_start(this->outputFileLabel, Gtk::PACK_SHRINK);

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

private:
    Gtk::Button selectButton;
    Gtk::Button renderButton;
    Gtk::Label  selectedFileLabel;
    Gtk::Label  outputFileLabel;
    Gtk::VBox  *vbox;
};

int main(int argc, char* argv[])
{
    Gtk::Main kit(argc, argv);
    static MyWindow window;
    window.show_all();
    Gtk::Main::run(window);
    return 0;
}
