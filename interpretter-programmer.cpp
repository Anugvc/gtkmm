
#include <gtkmm.h>
#include <iostream>

class MyWindow2 : public Gtk::Window
{
public:
    MyWindow2();

protected:
    // Signal handlers
    // bool on_button_press_event(GdkEventButton* button_event);
    // bool on_button_release_event(GdkEventButton* button_event);
    void on_combobox_changed();
    // Member widgets
    Gtk::Box m_VBox;
    Gtk::Button m_Button;
    Gtk::Scale m_Slider;
    Gtk::ComboBoxText m_ComboBox1;
    Gtk::ComboBoxText m_ComboBox2;
    Gtk::Label m_Label1;
    Gtk::Label m_Label2;

    Gtk::Label baud;
    Gtk::Label device;
    // Gtk::Label deviceName;
    Gtk::Label deviceName;
    Gtk::Button readDeviceName;
    Gtk::Button createDeviceName;
    Gtk::Button readFactoryData;
    Gtk::Button readDeviceData;

    Gtk::ScrolledWindow factoryWindow;
    Gtk::ScrolledWindow deviceWindow;

    Gtk::Box hbox1;
    Gtk::Box hbox2;
    Gtk::Box hbox3;
    Gtk::Box hbox4;
    Gtk::Box hbox5;

    Gtk::Label sampleData1;
    Gtk::Label sampleData2;
    Gtk::Label sampleData3;

    Gtk::Fixed fixed1;
    Gtk::Fixed fixed2;


};

MyWindow2::MyWindow2() : deviceName("Device name"),
                            baud("Baud"),
                            device("USB device"),
                            readDeviceName("Read Device Name"),
                            createDeviceName("Create Device Name"),
                            readFactoryData("Read Factory Data"),
                            readDeviceData("Read Device Data"),
                            sampleData1("Sample 1"),
                            sampleData2("Sample 2"),
                            sampleData3("Sample 3")
{
    // Set up the main window
    set_title("Interpreter Programmer");
    set_default_size(1000, 700);

    // Set up the vertical box container
    m_VBox.set_orientation(Gtk::ORIENTATION_VERTICAL);
    m_VBox.set_spacing(10);
    // m_VBox.set_margin(10);
    add(m_VBox);

    // Set up the button
    m_Button.set_hexpand(true);

    // Add items to the ComboBox:
    // m_ComboBox1.append(m_Label);
    m_ComboBox1.append("Option 1");
    m_ComboBox1.append("Option 2");
    m_ComboBox1.append("Option 3");

    m_ComboBox2.append("Option 1");
    m_ComboBox2.append("Option 2");
    m_ComboBox2.append("Option 3");

    hbox1.pack_start(device, Gtk::PACK_EXPAND_WIDGET);
    hbox1.pack_start(m_ComboBox1, Gtk::PACK_EXPAND_WIDGET);

    hbox2.pack_start(baud, Gtk::PACK_EXPAND_WIDGET);
    hbox2.pack_start(m_ComboBox2, Gtk::PACK_EXPAND_WIDGET);

    hbox3.pack_start(readDeviceName, Gtk::PACK_EXPAND_WIDGET);
    hbox3.pack_start(readDeviceData, Gtk::PACK_EXPAND_WIDGET);


    hbox4.pack_start(readFactoryData, Gtk::PACK_EXPAND_WIDGET);
    hbox4.pack_start(createDeviceName, Gtk::PACK_EXPAND_WIDGET);


    factoryWindow.set_size_request(300, 400);
    deviceWindow.set_size_request(300, 400);


    fixed1.set_size_request(300, 400);
    fixed2.set_size_request(300, 400);

    fixed1.add(sampleData1);
    fixed2.add(sampleData2);

    factoryWindow.add(fixed1);
    deviceWindow.add(fixed2);

    hbox5.pack_start(factoryWindow, Gtk::PACK_EXPAND_WIDGET);
    hbox5.pack_end(deviceWindow, Gtk::PACK_EXPAND_WIDGET);

    // Connect signal handler:
    m_ComboBox1.signal_changed().connect(sigc::mem_fun(*this, &MyWindow2::on_combobox_changed));

    // Pack widgets:
    // m_VBox.pack_start(m_Label1);
    m_VBox.pack_start(hbox1);
    m_VBox.pack_start(hbox2);
    m_VBox.pack_start(hbox3);
    m_VBox.pack_start(hbox4);
    m_VBox.pack_start(hbox5);
    
    
    
    // m_VBox.pack_start(m_Button, Gtk::PACK_SHRINK);

    
    // Show all the widgets
    show_all_children();

}



void MyWindow2::on_combobox_changed() {
    Glib::ustring text = m_ComboBox1.get_active_text();
    if (!text.empty()) {
        // m_Label.set_text("Selected: " + text);
    }
}


int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    MyWindow2 window;

    // Shows the window and returns when it is closed
    return app->run(window);
}
