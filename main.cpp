// #include <gtkmm.h>
// #include "db-model.hpp"


// int main(int argc, char *argv[])
// {
//     auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
//     DBModel _db;
//     Gtk::Window window;
//     window.set_size_request(800, 480);

//     // Shows the window and returns when it is closed
//     return app->run(window);
// }

#include <gtkmm.h>
#include <iostream>

class MyWindow : public Gtk::Window
{
public:
    MyWindow();

protected:
    // Signal handlers
    bool on_button_press_event(GdkEventButton* button_event);
    bool on_button_release_event(GdkEventButton* button_event);

    // Member widgets
    Gtk::Box m_VBox;
    Gtk::Button m_Button;
    Gtk::Scale m_Slider;
    Glib::RefPtr<Gtk::GestureLongPress> m_GestureLongPress;
    void on_gesture_long_press_pressed(double btn_x, double btn_y, int k, bool is_video);
    void on_gesture_long_press_end(GdkEventSequence*  sequence, int btn_no, bool is_video);

    bool on_motion_notify_event(GdkEventMotion* motion_event);
    double m_scale_val;
    double m_InputMin = 0;
    double m_InputMax = 300;
    double m_OutputMin = 0;
    double m_OutputMax = 100;
    double m_CurrentValue = 50;
    double m_PreviousMouseX;
    double m_CurrentMouseX ;
};

MyWindow::MyWindow()
    : m_Button("Hold to Slide"), m_Slider(Gtk::ORIENTATION_HORIZONTAL)
{
    // Set up the main window
    set_title("Button and Slider Example");
    set_default_size(300, 200);

    // Set up the vertical box container
    m_VBox.set_orientation(Gtk::ORIENTATION_VERTICAL);
    m_VBox.set_spacing(10);
    // m_VBox.set_margin(10);
    add(m_VBox);

    // Set up the button
    m_Button.set_hexpand(true);
    // m_Button.signal_button_press_event().connect(sigc::mem_fun(*this, &MyWindow::on_button_press_event));
    // m_Button.signal_button_release_event().connect(sigc::mem_fun(*this, &MyWindow::on_button_release_event));
    int k;
    m_GestureLongPress = Gtk::GestureLongPress::create(m_Button);
    m_GestureLongPress->set_propagation_phase(Gtk::PHASE_BUBBLE);
    m_GestureLongPress->signal_pressed().connect(sigc::bind(sigc::mem_fun(*this, &MyWindow::on_gesture_long_press_pressed), k, true), false);
    m_GestureLongPress->signal_end().connect(sigc::bind(sigc::mem_fun(*this, &MyWindow::on_gesture_long_press_end),k, true), false);
    m_GestureLongPress->set_touch_only(false);
    
    
    
    m_VBox.pack_start(m_Button, Gtk::PACK_SHRINK);

    // Set up the slider
    m_Slider.set_range(0, 100);
    m_Slider.set_value(50);
    m_Slider.set_hexpand(true);
    m_Slider.set_visible(false);
    m_VBox.pack_start(m_Slider, Gtk::PACK_SHRINK);

    m_Button.add_events(Gdk::BUTTON_PRESS_MASK); // Enable motion events for the button
    // m_Button.add_events(Gdk::BUTTON1_MASK); // Enable motion events for the button

    m_Button.add_events(Gdk::POINTER_MOTION_MASK); // Enable motion events for the button

    // m_Button.signal_button_release_event().connect(sigc::mem_fun(*this, &MyWindow::on_button_press_event), false);
    m_Button.signal_motion_notify_event().connect(sigc::mem_fun(*this, &MyWindow::on_motion_notify_event), false);

    // Allow motion events
    // add_events(Gdk::POINTER_MOTION_MASK);
    // Connect the motion notify signal
    // signal_motion_notify_event().connect(sigc::mem_fun(*this, &MyWindow::on_motion_notify_event));


    // Show all the widgets
    show_all_children();
    m_Slider.hide();

}

bool MyWindow::on_button_press_event(GdkEventButton* button_event)
{
    // Show the slider when the button is pressed
    // m_Slider.set_visible(true);
    // m_Slider.show();
    return true;
}

bool MyWindow::on_button_release_event(GdkEventButton* button_event)
{
    // Hide the slider when the button is released
    // m_Slider.set_visible(false);
    // m_Slider.hide();
    
    return true;
}



void MyWindow::on_gesture_long_press_pressed(double btn_x, double btn_y, int k, bool is_video)
{
    if(m_CurrentValue < 1)
    {
        m_OutputMax = 1;

    }
    else if (m_CurrentValue > 99)
    {
        m_OutputMax = 99;

    }
    else
    {
        m_OutputMax = m_CurrentValue;
        
    }
    m_InputMax = m_CurrentMouseX;

    m_Slider.show();
    std::cout << "BUTTON LONG PRESSED: " << m_OutputMax << std::endl;
} 


void MyWindow::on_gesture_long_press_end(GdkEventSequence*  sequence, int btn_no, bool is_video)
{
    std::cout << "BUTTON LONG PRESS END : " << m_OutputMax << std::endl;
    // if(m_OutputMax < 1)
    // {
    //     m_OutputMax = 1;
    // }
    m_scale_val = m_Slider.get_value();
    m_Slider.hide();
}


bool MyWindow::on_motion_notify_event(GdkEventMotion* motion_event)
{
    double slider_max = 100;
    double slider_min = 0;
    double x_max = 300;
    double x_min = 0;
    m_CurrentMouseX = motion_event->x ;

    

    // if (m_Slider.get_visible())
    // {
        // std::cout << "MOTION NOTIFY: x: " << motion_event->x << "  get_adjustment: "  << std::endl;

    //     // double new_value = m_Slider.get_adjustment()->get_value() + (motion_event->x - m_Slider.get_value());
    //     double new_value =  slider_min + ( motion_event->x - x_min) * (slider_max - slider_min)/ (x_max - x_min);

    //     if (new_value < 0) new_value = 0;
    //     if (new_value > 100) new_value = 100;
    //     m_Slider.set_value(new_value);
    // }
    if(m_Slider.get_visible())
    {
        double delta_x = motion_event->x - m_PreviousMouseX;

        // Map the mouse movement to the slider value change
        double slider_change = (delta_x / (m_InputMax - m_InputMin)) * (m_OutputMax - m_OutputMin);

        // Update the slider value
        // m_CurrentValue += slider_change;

        m_CurrentValue =  m_OutputMin + ( motion_event->x - m_InputMin) * (m_OutputMax - m_OutputMin)/ (m_InputMax - m_InputMin);

        std::cout << "MOTION NOTIFY: x: " << motion_event->x 
                  <<"  m_CurrentValue: " << m_CurrentValue
                  <<" m_OutputMax: "<< m_OutputMax
                  <<" m_InputMax: "<< m_InputMax
                  << std::endl;
        


        // Clamp the new value within the slider range
        //if (m_CurrentValue < m_OutputMin) m_CurrentValue = m_OutputMin;
        //if (m_CurrentValue > m_OutputMax) m_CurrentValue = m_OutputMax;



        // Set the new slider value
        m_Slider.set_value(m_CurrentValue);

        // Update the previous mouse position
        m_PreviousMouseX = motion_event->x;
    }



    return true;
}


int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    MyWindow window;

    // Shows the window and returns when it is closed
    return app->run(window);
}
