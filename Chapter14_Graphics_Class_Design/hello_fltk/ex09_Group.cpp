#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

using namespace Graph_lib;

ostream &operator<<(ostream &out, Point &a)
{
    out << "(" << a.x << "," << a.y << ")";
    return out;
}

struct Group : Shape
{
    void add_board_shape(Shape &shape) { b.push_back(shape); }
    void add_piece_shape(Shape &shape) { p.push_back(shape); }

    void draw_lines() const;
    void move_piece(int index, int dx, int dy);

    Vector_ref<Shape> shapes() { return b; }

private:
    Vector_ref<Shape> b;
    Vector_ref<Shape> p;
};

void Group::draw_lines() const
{
    for (int i = 0; i < b.size(); ++i)
    {
        b[i].draw();
    }
    for (int i = 0; i < p.size(); ++i)
    {
        p[i].draw();
    }
}

void Group::move_piece(int index, int fieldx, int fieldy)
{
    int dx = fieldx * 100;
    int dy = fieldy * 100;
    p[index].move(dx, dy);
}

void initialize_checkers_board(Group &group, Vector_ref<Graph_lib::Rectangle> &board)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            // pushback to vector_ref
            board.push_back(new Graph_lib::Rectangle(Point{j * 100, i * 100}, Point{j * 100 + 100, i * 100 + 100}));

            // setup color of checkers_board
            if (i % 2 == 0)
            {
                if (((i * 8) + j) % 2 == 0)
                {
                    board[i * 8 + j].set_fill_color(Color::black);
                }
                else
                {
                    board[i * 8 + j].set_fill_color(Color::white);
                }
            }
            else
            {
                if (((i * 8) + j) % 2 == 0)
                {
                    board[i * 8 + j].set_fill_color(Color::white);
                }
                else
                {
                    board[i * 8 + j].set_fill_color(Color::black);
                }
            }

            // add rectangle to checkers_board Group
            group.add_board_shape(board[i * 8 + j]);
        }
    }
}

void example(Simple_window &win)
{
    Point center{win.x_max() / 2, win.y_max() / 2};

    Group checkers_board;
    Vector_ref<Graph_lib::Rectangle> board;
    Vector_ref<Graph_lib::Circle> green_pieces;
    Vector_ref<Graph_lib::Circle> red_pieces;
    initialize_checkers_board(checkers_board, board);

    for (int j = 0; j < 2; ++j)
    {
        for (int i = 0; i < 4; ++i)
        {
            green_pieces.push_back(new Graph_lib::Circle(Point{i * 200 + 50 + j * 100, 150 + j * 100}, 40));
            green_pieces[green_pieces.size() - 1].set_color(Color::green);
            checkers_board.add_piece_shape(green_pieces[green_pieces.size() - 1]);
        }
    }
    for (int j = 0; j < 2; ++j)
    {
        for (int i = 0; i < 4; ++i)
        {
            red_pieces.push_back(new Graph_lib::Circle(Point{i * 200 + 50 + j * 100, 550 + j * 100}, 40));
            red_pieces[red_pieces.size() - 1].set_color(Color::red);
            checkers_board.add_piece_shape(red_pieces[red_pieces.size() - 1]);
        }
    }

    win.attach(checkers_board);
    win.wait_for_button();

    checkers_board.move_piece(0, 3, 4);
    win.attach(checkers_board);
    win.wait_for_button();
    checkers_board.move_piece(1, 4, 5);
    win.attach(checkers_board);
    win.wait_for_button();
    checkers_board.move_piece(12, -1, -4);
    win.attach(checkers_board);
    win.wait_for_button();
    checkers_board.move_piece(13, -1, -4);
    win.attach(checkers_board);

    win.wait_for_button();
}

int main()
{
    Point tl{100, 0};
    Simple_window win(tl, 1200, 800, "Simple Window");
    example(win);

    return 0;
}

// g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp ex09_Group.cpp -I/opt/homebrew/Cellar/fltk/1.3.8_1/include -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/opt/jpeg-turbo/lib `fltk-config --cxxflags --ldflags --use-images` -o hello_fltk -lpng -lturbojpeg && ./hello_fltk
