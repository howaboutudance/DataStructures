#ifndef MAZE_H
#define MAZE_H
#include <vector>
using namespace std;
class Maze{
    public:
        struct Cell{
            bool pathway;
            bool edge;
            bool end;
            char letter;
        };
        vector< vector<Cell> > maze;        
        Maze(int x, int y);
        void build(int x, int y);
        void prnt() const;
};
#endif
