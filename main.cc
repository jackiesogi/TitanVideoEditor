#include <gtkmm.h>
#include <gtkmm/button.h>

class MyWindow : public Gtk::Window
{
public:
    MyWindow()
    {    
        set_title("Simpledit");
        set_default_size(1080, 720);

        //GTK::Button button1;


        // Create a button and a label
        button.set_label("Click Me");
        label.set_text("Count: 0");

        // Connect the button click signal to a callback
        button.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_button_clicked));

        // Add widgets to the window
        box.pack_start(button);
        box.pack_start(label);
        add(box);

        show_all_children();
    }

private:
    Gtk::Button button;
    Gtk::Label label;
    Gtk::Box box;

    int count = 0;

    void on_button_clicked()
    {
        count++;
        label.set_text("Count: " + std::to_string(count));
    }
};

int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.example.gtkmmcounter");

    MyWindow window;

    return app->run(window);
}
