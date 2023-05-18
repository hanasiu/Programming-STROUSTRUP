#include "Simple_window.h"
#include "Graph.h"

class Arc : public Shape {
public:
    Arc(Point center, int radius, double start, double end)
        : Shape(), center(center), radius(radius), start_angle(start), end_angle(end)
    {
    }

    void draw_lines() const
    {
        if (color().visibility())
        {
            fl_color(color().as_int());
            fl_arc(center.x - radius, center.y - radius, radius + radius, radius + radius, start_angle, end_angle);
        }
    }

private:
    Point center;
    int radius;
    double start_angle;
    double end_angle;
};

void drill_05(Simple_window& win)
{
    // Create an arc object
    Arc arc(Point{100, 100}, 50, 40, 200);
    
    // Attach the arc to the window
    win.attach(arc);
     

    win.set_label("Canvas #1");
    win.wait_for_button();
}

int main()
{
    // Create a window
    Simple_window win(Point{100, 100}, 800, 600, "My Window");

    // Call the drill_05 function
    drill_05(win);

    return 0;
}
