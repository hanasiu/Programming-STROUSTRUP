#include "Simple_window.h"
#include "Graph.h"
#include <iostream>

using namespace std;

int main() {
    Shape i;
    Shape j = i;
}

//g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp ex02_Shape.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk


/*
ex02_Shape.cpp:8:11: error: calling a protected constructor of class 'Graph_lib::Shape'
    Shape i;
          ^
./Graph.h:157:5: note: declared protected here
    Shape() {};    
    ^
ex02_Shape.cpp:9:11: error: call to deleted constructor of 'Graph_lib::Shape'
    Shape j = i;
          ^   ~
./Graph.h:152:5: note: 'Shape' has been explicitly marked deleted here
    Shape(const Shape&) = delete;       // prevent copying
    ^
*/