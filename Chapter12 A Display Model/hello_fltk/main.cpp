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
    r1.set_style(Line_style(Line_style::solid, dpi_h * 1 /4));
    r1.set_color(Color::red);
    win.attach(r1);
    win.set_label("Canvas #4-1");
    win.wait_for_button();
};

int main()
{
    // Point top_left{500, 100}; // will be top left corner of window
    // Simple_window win{top_left, 600, 400, "Canvas"};
    Point top_left{0, 0}; // will be top left corner of window
    Simple_window win{top_left, Fl::w(), Fl::h(), "Canvas"};

    ex05(win);

    return 0;
}

// make
// ./hello_fltk
