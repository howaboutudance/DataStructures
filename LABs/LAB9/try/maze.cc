#include "maze.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

Maze::Maze(int x, int y){
    
    build(x, y);
}
void Maze::build(int x, int y){
    maze.resize(x);
    for(int i = 0; i < maze.size(); i++){
        maze[i].resize(y);
    }
    for(int i = 0; i < maze.size(); i++){
        for(int j = 0; j < maze[0].size(); j++){
            if(i == 0 || j == 0 || j == maze[0].size() - 1){
                Cell tmp = {false, true, false, ' '}; // edge
                maze[i][j] = tmp;
            } else if(i == maze.size() - 1){
                Cell tmp = {false, false, true, '@'}; // end
                maze[i][j] = tmp;
            } else {
                Cell tmp = {false, false, false, '#'}; // nothing yet
                maze[i][j] = tmp;
            }
        }
    }
}
void Maze::prnt() const{
    vector<string> lines;
    for(int i = 0; i < maze.size(); i++){
        for(int j = 0; j < maze[0].size(); j++){
            if(i == 0){
                lines.push_back(string(maze[i][j].letter));
            } else {
                lines[j] += string(maze[i][j].letter);
            }
        }
    }
    for(int i = 0; i < lines.size(); i++){
        cout << lines[i];
    }
    cout << endl;
}
