#ifndef FORM_H
#define FORM_H

#include <gtkmm.h>
#include <string>
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

    void on_select_button_clicked();
    void on_render_button_clicked();

private:
    Gtk::Button selectButton;
    Gtk::Button renderButton;
    Gtk::Label  selectedFileLabel;
    Gtk::Label  outputFileLabel;
    Gtk::VBox  *vbox;
};

#endif  // FORM_H