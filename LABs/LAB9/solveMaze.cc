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
    startX = xy[0];
    startY = xy[1];
    while(end != "E"){
        
    }
}
//void prntAll() const{
//}
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
bool isBlocked(int x, int y, vector<vector<string> > &maze){
    
}
