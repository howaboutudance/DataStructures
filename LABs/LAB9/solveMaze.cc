#include <vector>
#include <iostream>
#include <string>
#include "solveMaze.h"
using namespace std;

solveMaze::solveMaze(vector<vector<string> > & maze){
    create(maze);
}
solveMaze::~solveMaze(){
    allPaths.clear();
    originalMaze.clear();
}
void solveMaze::prnt(){
    for(int i = 0; i < originalMaze.size(); i++){
        for(int j = 0; j < originalMaze[0].size(); j++){
            cout << originalMaze[i][j];
        }
        cout << endl;
    }
}
void solveMaze::prnt(vector<vector<string> > & maze){
    for(int i = 0; i < maze.size(); i++){
        for(int j = 0; j < maze[0].size(); j++){
            cout << maze[i][j];
        }
        cout << endl;
    }
}

void solveMaze::aPath(){
    vector<int> xy; xy = start(); 
    vector<vector<string> > newMaze;
    newMaze = cpy(originalMaze);
    solveMaze one(newMaze);
    vector<vector<int> > paths;
    paths.push_back(xy);
    int startX = xy[0];
    int startY = xy[1];
    string end = "_";
    while(end != "E"){

        // NORTH
        if(isSafe(startX, startY - 1) && isBlocked(startX, startY - 1, one.originalMaze)){
            cout << " north ";
            startY -= 1;
            if(one.originalMaze[startX][startY] != "E"){
                one.originalMaze[startX][startY] = "\033[31m█\033[0m";
                vector<int> tmp = {startX, startY};
                paths.push_back(tmp);
            } else {
                end = "E";
            }
        }

        // EAST
        else if(isSafe(startX + 1, startY) && isBlocked(startX + 1, startY, one.originalMaze)){
            cout << " east ";
            startX += 1;
            if(one.originalMaze[startX][startY] != "E"){
                one.originalMaze[startX][startY] = "\033[31m█\033[0m";
                vector<int> tmp = {startX, startY};
                paths.push_back(tmp);
            } else {
                end = "E";
            }
        }

        // SOUTH
        else if(isSafe(startX, startY + 1) && isBlocked(startX, startY + 1, one.originalMaze)){
            cout << " south ";
            startY += 1;
            if(one.originalMaze[startX][startY] != "E"){
                one.originalMaze[startX][startY] = "\033[31m█\033[0m";
                vector<int> tmp = {startX, startY};
                paths.push_back(tmp);
            } else {
                end = "E";
            }
        }

        // WEST
        else if(isSafe(startX - 1, startY) && isBlocked(startX - 1, startY, one.originalMaze)){
            cout << " west ";
            startX -= 1;
            if(one.originalMaze[startX][startY] != "E"){
                one.originalMaze[startX][startY] = "\033[31m█\033[0m";
                vector<int> tmp = {startX, startY};
                paths.push_back(tmp);
            } else {
                end = "E";
            }
        } else {
            one.originalMaze[startX][startY] = "\033[31m█\033[0m";
            vector<int> tmp = paths.back();
            startX = tmp[0];
            startY = tmp[1];
            paths.pop_back();
        }
        one.prnt();
    }
}
void solveMaze::prntAll(){
    if(!allPaths.empty()){
        for(int i = 0; i < allPaths.size(); i++){
            allPaths[i].prnt();
            cout << endl;
        }
    }
}
vector<vector<string> > solveMaze::cpy(vector<vector<string> > & maze){
    vector<vector<string> > newMaze(maze.size());
    for(int i = 0; i < maze.size(); i++){
        for(int j = 0; j < maze[0].size(); j++){
            newMaze[i].push_back(maze[i][j]);
        }
    }
    return newMaze;
}
void solveMaze::create(vector<vector<string> > & maze){
    // In the future I will have an overloaded function to
    // actually create a map. For now I just pass it through.
    originalMaze = cpy(maze);
}
bool solveMaze::isSafe(int x, int y){
    if(x < 0 || y < 0 || x >= originalMaze.size() || y >= originalMaze[0].size()){
        return false;
    }
    return true;
}
vector<int> solveMaze::start(){
    vector<int> tmp;
    for(int i = 0; i < originalMaze.size(); i++){
        for(int j = 0; j < originalMaze[0].size(); j++){
            if(originalMaze[i][j] == "B"){
                tmp.push_back(i);
                tmp.push_back(j);
            }
        }
    }
    return tmp;
}
bool solveMaze::isBlocked(int x, int y, vector<vector<string> > &maze){
    if(maze[x][y] == " "){
        return true;
    }
    return false;
}
