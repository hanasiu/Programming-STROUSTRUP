#include "Simple_window.h"
#include "Graph.h"


void example(Simple_window& win)
{
   Vector_ref<Rectangle> rgb_chart;
   int i=0;
   int j=0;
   for(int r = 0; r<=255; r+=15)
   for(int g = 0; g<=255; g+=15)
   for(int b = 0; b<=255; b+=15) {
    if(j*13>750) {
        ++i;
        j=0;
    }
    rgb_chart.push_back(new Rectangle{Point{i*13, j*13}, 13, 13});
    rgb_chart[rgb_chart.size()-1].set_fill_color(fl_rgb_color(r, g, b));
    win.attach(rgb_chart[rgb_chart.size()-1]);
    ++j;
   } 

    win.set_label("Canvas #1");
    win.wait_for_button();
}


int main()
{
    // Create a window
    Simple_window win(Point{100, 100}, 1600, 780, "My Window");

    // Call the drill_05 function
    example(win);

    return 0;
}

// g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp ex07_Rgb.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
