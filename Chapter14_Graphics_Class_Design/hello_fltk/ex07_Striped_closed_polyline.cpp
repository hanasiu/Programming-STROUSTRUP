#include "Simple_window.h"
#include "Graph.h"
#include <iostream>
#include <algorithm>

using namespace std;

class Striped_closed_polyline : public Closed_polyline
{
public:
    Striped_closed_polyline(initializer_list<Point> lst) : Closed_polyline{lst} {}

    void draw_lines() const;
};

inline pair<double, double> line_intersect(Point p1, Point p2, Point p3, Point p4, bool &parallel)
{
    double x1 = p1.x;
    double x2 = p2.x;
    double x3 = p3.x;
    double x4 = p4.x;
    double y1 = p1.y;
    double y2 = p2.y;
    double y3 = p3.y;
    double y4 = p4.y;

    double denom = ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
    if (denom == 0)
    {
        parallel = true;
        return pair<double, double>(0, 0);
    }
    parallel = false;
    return pair<double, double>(((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / denom,
                                ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / denom);
}

bool line_segment_intersect(Point p1, Point p2, Point p3, Point p4, Point &intersection)
{
    bool parallel;
    pair<double, double> u = line_intersect(p1, p2, p3, p4, parallel);
    if (parallel || u.first < 0 || u.first > 1 || u.second < 0 || u.second > 1)
        return false;
    intersection.x = p1.x + u.first * (p2.x - p1.x);
    intersection.y = p1.y + u.first * (p2.y - p1.y);
    return true;
}

void Striped_closed_polyline::draw_lines() const
{
    if (number_of_points() > 1)
    {
        if (fill_color().visibility())
        {
            fl_color(fill_color().as_int());

            // get bounding box, pad with 5px in x-direction
            int x_min = point(0).x;
            int x_max = point(0).x;
            int y_min = point(0).y;
            int y_max = point(0).y;
            for (int i = 0; i < number_of_points(); ++i)
            {
                if (point(i).x < x_min)
                    x_min = point(i).x;
                if (point(i).x > x_max)
                    x_max = point(i).x;
                if (point(i).y < y_min)
                    y_min = point(i).y;
                if (point(i).y > y_max)
                    y_max = point(i).y;
            }
            x_min -= 5;
            x_max += 5;

            // for each horizontal line in bounding box, check for intersection with all polygon lines
            // and add found intersections to vector of points
            for (int y = y_min; y < y_max; y += 4)
            {
                vector<Point> is; // vector of intersections
                Point intersec;
                for (int i = 1; i < number_of_points(); ++i)
                {
                    if (line_segment_intersect(Point{x_min, y}, Point{x_max, y}, point(i), point(i - 1), intersec))
                        is.push_back(intersec);
                }
                // add closing line
                if (line_segment_intersect(Point{x_min, y}, Point{x_max, y},
                                           point(number_of_points() - 1), point(0), intersec))
                    is.push_back(intersec);

                // sort vector by x-values
                std::sort(is.begin(), is.end(), [](const Point &p1, const Point &p2)
                          { return p1.x < p2.x; });

                // draw line between every 2nd pair of points
                for (int i = 1; i < is.size(); i += 2)
                {
                    fl_line(is[i - 1].x, is[i - 1].y, is[i].x, is[i].y);
                }
            }
            fl_color(color().as_int()); // reset color
        }

        
        if (color().visibility()&& number_of_points()>1) {
        for (unsigned int i=1; i<number_of_points(); ++i)
            fl_line(point(i-1).x,point(i-1).y,point(i).x,point(i).y);
            // draw closing line
            fl_line(point(number_of_points() - 1).x,
                    point(number_of_points() - 1).y,
                    point(0).x,
                    point(0).y);
        }
    }
}

void example(Simple_window &win)
{
    Striped_closed_polyline i({Point{100, 100}, Point{150, 200}, Point{400, 400}, Point{200, 100}});
    i.set_color(Color::blue);
    i.set_fill_color(Color::green);
    win.attach(i);

    win.set_label("Canvas #1");
    win.wait_for_button();
}

int main()
{
    // Create a window
    Simple_window win(Point{100, 100}, 800, 600, "My Window");

    example(win);

    return 0;
}
// g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp ex07_Striped_closed_polyline.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
