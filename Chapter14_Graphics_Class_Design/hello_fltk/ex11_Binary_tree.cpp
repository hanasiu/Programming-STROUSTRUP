#include "Simple_window.h"
#include "Graph.h"
#include <iostream>
#include <algorithm>
#include <cmath>

/*
11. Define a Binary_tree class derived from Shape. 
Give the number of levels as a parameter (levels==0 means no nodes, 
levels==1 means one node, levels==2 means one top node with two sub-nodes, levels==3 means one top node
with two sub-nodes each with two sub-nodes, etc.). Let a node be represented by a 
small circle. Connect the nodes by lines (as is conventional). P.S. In computer science,
 trees grow downward from a top node (amusingly, but logically, often called the root).
*/
using namespace std;

struct Arrow : Shape {
    Arrow(Point tail, Point head);
    void draw_lines() const;

private:
    Point head;
    Point tail;
};

Arrow::Arrow(Point tail, Point head)
    : head(head), tail(tail)
{
}

void Arrow::draw_lines() const {
    fl_line(tail.x, tail.y, head.x, head.y);

    // Calculate the direction vector of the arrow
    double dx = head.x - tail.x;
    double dy = head.y - tail.y;
    double angle = atan2(dy, dx);

    // Calculate the arrowhead points
    double arrow_size = 10.0;
    double arrow_angle = M_PI / 6.0;  // 30 degrees
    double angle1 = angle + arrow_angle;
    double angle2 = angle - arrow_angle;
    int x1 = head.x - arrow_size * cos(angle1);
    int y1 = head.y - arrow_size * sin(angle1);
    int x2 = head.x - arrow_size * cos(angle2);
    int y2 = head.y - arrow_size * sin(angle2);

    fl_line(head.x, head.y, x1, y1);
    fl_line(head.x, head.y, x2, y2);
}

struct Binary_tree : Shape {
    Binary_tree(Point xy, int levels, string edge_style);   // edge_style: "au" or
                                                            // "ad" for arrow up or
                                                            // down; else normal
    virtual void draw_lines() const;
    void move(int dx, int dy);
    int levels() const { return lvls; }
    void set_node_label(string n, string lbl);
protected:
    Vector_ref<Shape> edges;
    Vector_ref<Text> labels;
private:
    int lvls;   // 1 level: 1 node; 2 levels: 1 node, two childs, etc.
};

Binary_tree::Binary_tree(Point xy, int levels, string edge_style) : lvls(levels)
{
    if (levels<0) error("Binary_tree: levels must be at least zero");
    if (levels==0) return;  // tree ist empty
    add(xy);    // if levels==1, only root is added
    int dx = 35;    // distance between nodes on lowest level
    int dy = 100;    // distance between levels
    for (int i = 2; i<=levels; ++i) {
        for (int j = 0; j<pow(2,i-1); ++j) {
            int x = xy.x - ((pow(2,i-1)-1)/2-j) * pow(2,levels-i)*dx;
            int y = xy.y + (i-1)*dy;
            add(Point{x,y});
        }
    }

    // add lines
    for (int i = 0; i<number_of_points()/2; ++i) {
        if (edge_style=="ad") { // arrow down
            edges.push_back(new Arrow(point(i),
                Point{point(2*i+1).x,point(2*i+1).y-12}));
            edges.push_back(new Arrow(point(i),
                Point{point(2*i+2).x,point(2*i+2).y-12}));
        }
        else if (edge_style=="au") {    // arrow up
            edges.push_back(new Arrow(point(2*i+1),
                Point{point(i).x,point(i).y+12}));
            edges.push_back(new Arrow(point(2*i+2),
                Point{point(i).x,point(i).y+12}));
        }
        else {  // normal line
            edges.push_back(new Line(point(i),point(2*i+1)));
            edges.push_back(new Line(point(i),point(2*i+2)));
        }
    }

    // add label - empty for the moment
    for (int i = 0; i<number_of_points(); ++i)
        labels.push_back(new Text(Point{point(i).x+13,point(i).y-13},""));
}

//------------------------------------------------------------------------------

void Binary_tree::draw_lines() const
{
    if (color().visibility()) {
        for (int i = 0; i<edges.size(); ++i)
            edges[i].draw();

        // draw labels
        for (int i = 0; i<number_of_points(); ++i)
            labels[i].draw();

        // draw circles
        const int r = 12;
        fl_color(fl_rgb_color(192,192,192));
        for (int i = 0; i<number_of_points(); ++i)
            fl_pie(point(i).x-r,point(i).y-r,r+r-1,r+r-1,0,360);
        fl_color(color().as_int());	// reset color
        for (int i = 0; i<number_of_points(); ++i)
            fl_arc(point(i).x-r,point(i).y-r,r+r,r+r,0,360);
    }
}

//------------------------------------------------------------------------------

void Binary_tree::move(int dx, int dy)
{
    Shape::move(dx,dy);
    for (int i = 0; i<edges.size(); ++i)
        edges[i].move(dx,dy);
    for (int i = 0; i<number_of_points(); ++i)
            labels[i].move(dx,dy);
}

//------------------------------------------------------------------------------

// set label of node specified by string n to lbl. n is a sequence of l and r
// for navigating left and right in the tree
void Binary_tree::set_node_label(string n, string lbl)
{
    if (n.size()<1 || n.size()>lvls) error("set_node_label: illegal node string ",n);
    istringstream iss(n);
    char ch;
    iss.get(ch);    // look at first character
    int n_idx = 0;  // node index in point list
    if (ch == 'R') {
        switch (ch) {
        case 'R':
            labels[n_idx].set_label(lbl);
            n_idx = 1;
            return;
        default:
            error("set_node_label: illegal character in node string: ",string(1,ch));
        }
    } else iss.unget();
    while (iss.get(ch)) {
        switch (ch) {
        case 'l':
            n_idx = 2*n_idx + 1;
            break;
        case 'r':
            n_idx = 2*n_idx + 2;
            break;
        default:
            error("set_node_label: illegal character in node string: ",string(1,ch));
        }
    }
    labels[n_idx].set_label(lbl);
}

class Triangle_Binary_tree : public Binary_tree {
public:
    Triangle_Binary_tree(Point xy, int levels, string edge_style)
            : Binary_tree(xy, levels, edge_style)
    {
    }   // edge_style: "au" or
                                                            // "ad" for arrow up or
                                                           // down; else normal
    void draw_lines() const override;
    //void move(int dx, int dy);
    //int levels() const { return lvls; }
    void set_node_label(string n, string lbl);
// protected:
//     Vector_ref<Shape> edges;
//     Vector_ref<Text> labels;
// private:
//     int lvls; 
};


void Triangle_Binary_tree::draw_lines() const
{
    if (color().visibility()) {
        for (int i = 0; i < edges.size(); ++i)
            edges[i].draw();

        // Draw labels
        for (int i = 0; i < number_of_points(); ++i)
            labels[i].draw();

        // Draw triangles instead of circles
        const int size = 12; // Size of the triangle
        //fl_color(fl_rgb_color(192, 192, 192));
        for (int i = 0; i < number_of_points(); ++i) {
            Point p = point(i);
            int x = p.x;
            int y = p.y;
            int x1 = x - size;
            int x2 = x + size;
            int y1 = y - size * 2; // Adjusted to invert the triangle
            int y2 = y;
            fl_line(x, y1, x1, y2);
            fl_line(x1, y2, x2, y2);
            fl_line(x2, y2, x, y1);
        }

        fl_color(color().as_int()); // Reset color
    }
}


//------------------------------------------------------------------------------
void example(Simple_window &win)
{
   Binary_tree bt(Point{600,50},6,"");
    win.attach(bt);
    win.wait_for_button();

    bt.move(50,50);
    win.wait_for_button();
    bt.move(-50,-50);
    win.wait_for_button();

    win.detach(bt);

    Binary_tree bt2(Point{600,50},6,"ad");
    win.attach(bt2);
    win.wait_for_button();

    win.detach(bt2);

    Binary_tree bt3(Point{600,50},6,"au");
    win.attach(bt3);
    win.wait_for_button();

    bt3.set_node_label("R","Root");
    bt3.set_node_label("l","l");
    bt3.set_node_label("lr","lr");
    bt3.set_node_label("lrl","lrl");
    bt3.set_node_label("lrlr","lrlr");
    bt3.set_node_label("lrlrl","lrlrl");
    //bt3.set_node_label("","");
    //bt3.set_node_label("x","x");
    //bt3.set_node_label("lrlx","lrlx");
    //bt3.set_node_label("lrlrlrl","lrlrlrl");
    win.wait_for_button();

    win.detach(bt3);

    Triangle_Binary_tree tbt(Point{600,50},6,"");
    win.attach(tbt);
    win.wait_for_button();
}

int main()
{
    Point tl{100, 0};
    Simple_window win(tl, 1200, 800, "Simple Window");
    example(win);

    return 0;
}



// g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp ex11_Binary_tree.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
