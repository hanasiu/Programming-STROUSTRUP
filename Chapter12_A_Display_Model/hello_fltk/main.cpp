#include "Simple_window.h"
#include "Graph.h"


using namespace Graph_lib; // our graphics facilities are in Graph_lib (defined in Graph.h)

void ex01(Simple_window &win)
{
    Rectangle r{Point{200, 200}, 100, 50};
    r.set_color(Color::blue);
    win.attach(r);
    win.set_label("Canvas #1-1");
    win.wait_for_button();

    Polygon poly;
    poly.add(Point{300, 200});
    poly.add(Point{350, 100});
    poly.add(Point{400, 200});

    poly.set_color(Color::red);
    win.attach(poly);
    win.set_label("Canvas #1-2");
    win.wait_for_button();
}

void ex02(Simple_window &win)
{
    Rectangle r{Point{200, 200}, 100, 50};
    r.set_color(Color::blue);
    win.attach(r);
    win.set_label("Canvas #2-1");
    win.wait_for_button();

    Text t{Point{220, 220}, "Howdy!"};
    win.attach(t);
    win.set_label("Canvs #2-2");
    win.wait_for_button();
}

void ex03(Simple_window &win)
{
    Text k{Point{150, 150}, "K"};
    Text y{Point{280, 150}, "Y"};
    win.attach(k);
    win.attach(y);
    k.set_font(Graph_lib::Font::times_bold);
    k.set_font_size(150);
    k.set_color(Color::blue);

    y.set_font(Graph_lib::Font::times_bold);
    y.set_font_size(150);
    y.set_color(Color::green);

    win.set_label("Canvs #3");
    win.wait_for_button();
}

void ex04(Simple_window &win)
{
    Rectangle r1{Point{100, 100}, 100, 100};
    r1.set_fill_color(Color::white);
    win.attach(r1);
    win.set_label("Canvas #4-1");
    win.wait_for_button();

    Rectangle r2{Point{200, 100}, 100, 100};
    r2.set_fill_color(Color::red);
    win.attach(r2);
    win.set_label("Canvas #4-2");
    win.wait_for_button();

    Rectangle r3{Point{300, 100}, 100, 100};
    r3.set_fill_color(Color::white);
    win.attach(r3);
    win.set_label("Canvas #4-3");
    win.wait_for_button();

    Rectangle r4{Point{100, 200}, 100, 100};
    r4.set_fill_color(Color::red);
    win.attach(r4);
    win.set_label("Canvas #4-4");
    win.wait_for_button();

    Rectangle r5{Point{200, 200}, 100, 100};
    r5.set_fill_color(Color::white);
    win.attach(r5);
    win.set_label("Canvas #4-5");
    win.wait_for_button();

    Rectangle r6{Point{300, 200}, 100, 100};
    r6.set_fill_color(Color::red);
    win.attach(r6);
    win.set_label("Canvas #4-6");
    win.wait_for_button();

    Rectangle r7{Point{100, 300}, 100, 100};
    r7.set_fill_color(Color::white);
    win.attach(r7);
    win.set_label("Canvas #4-7");
    win.wait_for_button();

    Rectangle r8{Point{200, 300}, 100, 100};
    r8.set_fill_color(Color::red);
    win.attach(r8);
    win.set_label("Canvas #4-8");
    win.wait_for_button();

    Rectangle r9{Point{300, 300}, 100, 100};
    r9.set_fill_color(Color::white);
    win.attach(r9);
    win.set_label("Canvas #4-9");
    win.wait_for_button();
}

void ex05(Simple_window &win)
{
    // Get the screen DPI
    float dpi_h, dpi_v;
    Fl::screen_dpi(dpi_h, dpi_v);

    Rectangle r1{Point{Fl::w() * 1 / 3 / 2, Fl::h() * 1 / 4 / 2},
                 Fl::w() * 2 / 3, Fl::h() * 3 / 4};
    r1.set_fill_color(Color::white);
    r1.set_style(Line_style(Line_style::solid, dpi_h * 1 / 4));
    r1.set_color(Color::red);
    win.attach(r1);
    win.set_label("Canvas #4-1");
    win.wait_for_button();
};

void ex07(Simple_window &win)
{
    // Get the screen DPI
    float dpi_h, dpi_v;
    Fl::screen_dpi(dpi_h, dpi_v);

    Rectangle r1{Point{500, 400},
                 800, 400};
    r1.set_fill_color(Color::white);
    r1.set_style(Line_style(Line_style::solid, dpi_h * 1 / 10));
    r1.set_color(Color::green);
    win.attach(r1);

    Polygon roof;
    roof.add(Point{500, 400});
    roof.add(Point{1300, 400});
    roof.add(Point{900, 100});
    roof.set_style(Line_style(Line_style::solid, dpi_h * 1 / 10));
    roof.set_fill_color(Color::white);
    roof.set_color(Color::green);
    win.attach(roof);

    Polygon chimney;
    chimney.add(Point{1100, 250});
    chimney.add(Point{1100, 100});
    chimney.add(Point{1150, 100});
    chimney.add(Point{1150, 284});
    chimney.set_style(Line_style(Line_style::solid, dpi_h * 1 / 10));
    chimney.set_fill_color(Color::white);
    chimney.set_color(Color::green);
    win.attach(chimney);

    Rectangle hole{Point{1100, 100}, 50, 50};
    hole.set_fill_color(Color::black);
    hole.set_color(Color::green);
    hole.set_style(Line_style(Line_style::solid, dpi_h * 1 / 15));
    win.attach(hole);

    Rectangle door{Point{500, 500},
                   200, 300};
    door.set_fill_color(Color::white);
    door.set_style(Line_style(Line_style::solid, dpi_h * 1 / 10));
    door.set_color(Color::green);
    win.attach(door);

    Circle doorKnob{Point{530, 650}, 10};
    doorKnob.set_color(Color::green);
    doorKnob.set_style(Line_style(Line_style::solid, dpi_h * 1 / 20));
    win.attach(doorKnob);

    Rectangle window1{Point{900, 500},
                      100, 100};
    window1.set_fill_color(Color::white);
    window1.set_style(Line_style(Line_style::solid, dpi_h * 1 / 20));
    window1.set_color(Color::green);
    win.attach(window1);

    Rectangle window2{Point{1050, 500},
                      100, 100};
    window2.set_fill_color(Color::white);
    window2.set_style(Line_style(Line_style::solid, dpi_h * 1 / 20));
    window2.set_color(Color::green);
    win.attach(window2);

    win.set_label("Canvas #4-1");
    win.wait_for_button();
};

void ex08(Simple_window &win)
{
     // Get the screen DPI
    float dpi_h, dpi_v;
    Fl::screen_dpi(dpi_h, dpi_v);

    Rectangle r1{Point{Fl::w() * 1 / 3 / 2, Fl::h() * 1 / 4 / 2},
                 Fl::w() * 2 / 3, Fl::h() * 3 / 4};
    r1.set_fill_color(Color::white);
    r1.set_style(Line_style(Line_style::solid, dpi_h * 1 / 4));
    r1.set_color(Color::white);
    win.attach(r1);


    Circle circle2{Point{950, 400}, 150};
    circle2.set_color(Color::black);
    circle2.set_style(Line_style(Line_style::solid, dpi_h * 1 / 5));
    win.attach(circle2);

    Circle circle4{Point{775, 550}, 150};
    circle4.set_color(Color::yellow);
    circle4.set_style(Line_style(Line_style::solid, dpi_h * 1 / 5));
    win.attach(circle4);

    Circle circle5{Point{1125, 550}, 150};
    circle5.set_color(Color::green);
    circle5.set_style(Line_style(Line_style::solid, dpi_h * 1 / 5));
    win.attach(circle5);

    Circle circle1{Point{600, 400}, 150};
    circle1.set_color(Color::blue);
    circle1.set_style(Line_style(Line_style::solid, dpi_h * 1 / 5));
    win.attach(circle1);
    
    
    Circle circle3{Point{1300, 400}, 150};
    circle3.set_color(Color::red);
    circle3.set_style(Line_style(Line_style::solid, dpi_h * 1 / 5));
    win.attach(circle3);

    win.set_label("Canvas #4-1");
    win.wait_for_button();
};

void ex09(Simple_window &win)
{
     // Get the screen DPI
    float dpi_h, dpi_v;
    Fl::screen_dpi(dpi_h, dpi_v);

    Rectangle r1{Point{Fl::w() * 1 / 3 / 2, Fl::h() * 1 / 4 / 2},
                 Fl::w() * 2 / 3, Fl::h() * 3 / 4};
    r1.set_fill_color(Color::white);
    r1.set_style(Line_style(Line_style::solid, dpi_h * 1 / 4));
    r1.set_color(Color::white);
    win.attach(r1);

    Image cal{Point{500,500}, "rita.jpg"};
    win.attach(cal);

    win.set_label("Canvas #4-1");

    Text txt{Point{500, 490},"image exercise"};
    win.attach(txt);

    win.wait_for_button();
};

// draw the file diagram from §12.8
void ex10(Simple_window& win)
{
    Rectangle fltk1{Point{400,10},120,40};
    fltk1.set_fill_color(Color::yellow);
    win.attach(fltk1);
    Rectangle fltk2{Point{406,16},120,40};
    fltk2.set_fill_color(Color::yellow);
    win.attach(fltk2);
    Rectangle fltk3{Point{412,22},120,40};
    fltk3.set_fill_color(Color::yellow);
    win.attach(fltk3);
    Text fltk_txt{Point{418,42},"FLTK headers"};
    win.attach(fltk_txt);

    Rectangle win_rect{{389,130},166,80};
    win_rect.set_fill_color(Color::yellow);
    win.attach(win_rect);
    Text win_txt0{{389,127},"Window.h:"};
    win_txt0.set_font(Graph_lib::Font::helvetica_bold);
    win.attach(win_txt0);
    Text win_txt1{{395,150},"// window interface:"};
    win.attach(win_txt1);
    Text win_txt2{{395,170},"class Window {...};"};
    win_txt2.set_font(Graph_lib::Font::helvetica_bold);
    win.attach(win_txt2);
    Text win_txt3{Point{395,190},"..."};
    win.attach(win_txt3);

    Open_polyline win_fltk;
    win_fltk.add({472,130});
    win_fltk.add({472,62});
    win.attach(win_fltk);
    Polygon win_fltk_arw;
    win_fltk_arw.add({472,62});
    win_fltk_arw.add({474,67});
    win_fltk_arw.add({470,67});
    win_fltk_arw.set_fill_color(Color::black);
    win.attach(win_fltk_arw);

    win.wait_for_button();
}

void ex11(Simple_window& win)
{
    Polygon triangle;
    triangle.add(Point{800,550});
    triangle.add(Point{850,500});
    triangle.add(Point{900,600});
    

    triangle.set_color(Color::red);
    win.attach(triangle);

    Rectangle rectangle{Point{800,500},100,100};
    rectangle.set_color(Color::green);
    win.attach(rectangle);

    Polygon pentagon;
    pentagon.add(Point{800,600});
    pentagon.add(Point{900,600});
    pentagon.add(Point{950,550});
    pentagon.add(Point{850,450});
    pentagon.add(Point{750,550});
    
    pentagon.set_color(Color::blue);
    win.attach(pentagon);

    win.wait_for_button();
}


int main()
{
    // Point top_left{500, 100}; // will be top left corner of window
    // Simple_window win{top_left, 600, 400, "Canvas"};
    Point top_left{0, 0}; // will be top left corner of window
    Simple_window win{top_left, Fl::w(), Fl::h(), "Canvas"};
    //g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp main.cpp `fltk-config --ldflags --use-images` -o hello_fltk && ./hello_fltk
    ex11(win);

    return 0;
}

// make
// ./hello_fltk
