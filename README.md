# gtkmm
gtkmm-demo-samples



## Interpretter Programmer Demo

- This is a rough skeleton for the Interpretter Programmer applcation using gtkmm
- To run this, ensure gtkmm 3 is intalled: **sudo apt-get install libgtkmm-3.0-dev**
- Clone the repo
- Then in terminal, go to directory where repo was cloned.
- run ** mkdir build && cd build **
- ** cmake .. **
- ** make ** 
- ** ./interpretter-programmer **


## Slider-unit demo

- A simple gtkmm program to demonstrate slider control using a button
- The slider will appear when user long presses the button. Then the user can 
   slide across the screen to adjust the slider value. When the user releases
   the button, the slider is automatically hidden.
- This is particularly usefull when a slider needs to be implemented on a 
   touch interface, making it more interactive.
   
- How to run:
   Open in cmd line
   $ mkdir build && cd build
   $ cmake ..
   $ make
   $ ./slider-unit
