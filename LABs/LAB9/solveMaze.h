#include <vector>
#include <iostream>
#include <string>
using namespace std;

#ifndef SOLVEMAZE_H
#define SOLVEMAZE_H
class solveMaze{
    private:
        vector<solveMaze> allPaths;
        vector<vector<string> > originalMaze;
        vector<vector<string> > cpy(vector<vector<string> > & maze);
        void create(vector<vector<string> > & maze);
        vector<int> start();
        bool isBlocked(int x, int y, vector<vector<string> > &maze);
        bool isSafe(int x, int y);
    public:
        solveMaze(vector<vector<string> > & maze);
        ~solveMaze();
        void prnt();
        void prnt(vector<vector<string> > & maze);
        void aPath();
        void prntAll();
};
#endif
