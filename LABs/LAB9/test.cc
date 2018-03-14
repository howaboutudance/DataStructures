#include <vector>
#include <iostream>
#include <string>
using namespace std;
vector<vector<vector<string> > > allPaths;
void prnt(vector<vector<string> > & m){
    for(int i = 0; i < m.size(); i++){
        for(int j = 0; j < m[0].size(); j++){
            cout << m[i][j];
        }
        cout << endl;
    }
}

vector<vector<string> > cpy(vector<vector<string> > & m){
    vector<vector<string> > newMaze(m.size());
    for(int i = 0; i < m.size(); i++){
        for(int j = 0; j < m[0].size(); j++){
            newMaze[i].push_back(m[i][j]);
        }
    }
    return newMaze;
}

void path(vector<vector<string> > m){
    vector<vector<int> > aPath;
    int startX;
    int startY;
    string end = "_";
    for(int i = 0; i < m.size(); i++){
        for(int j = 0; j < m[0].size(); j++){
            if(m[i][j] == "B"){
                startX = i;
                startY = j;
            }
        }
    }
    while(end != "E"){
        // NORTH
        if(startY - 1 >= 0){
            if(m[startX][startY - 1] != "B" && m[startX][startY - 1] != "▒" && m[startX][startY - 1] != "E" && m[startX][startY - 1] == " " && m[startX][startY - 1] != "\033[31m█\033[0m"){
                startY -= 1;
                m[startX][startY + 1] = "\033[31m█\033[0m";
                vector<int> xy = {startX, startY};
                aPath.push_back(xy);
            }
        } 
        // EAST
        else if(startX + 1 < m.size()){
            if(m[startX + 1][startY] != "B" && m[startX + 1][startY] != "▒" && m[startX + 1][startY] != "E" && m[startX + 1][startY] == " " && m[startX + 1][startY] != "\033[31m█\033[0m"){
                startX += 1;
                m[startX - 1][startY] = "\033[31m█\033[0m";
                vector<int> xy = {startX, startY};
                aPath.push_back(xy);
            }
        }
        // SOUTH
        else if(startY + 1 < m[0].size()){
            if(m[startX][startY + 1] != "B" && m[startX][startY + 1] != "▒" && m[startX][startY + 1] != "E" && m[startX][startY + 1] == " " && m[startX][startY + 1] != "\033[31m█\033[0m"){
                startY += 1;
                m[startX][startY - 1] = "\033[31m█\033[0m";
                vector<int> xy = {startX, startY};
                aPath.push_back(xy);
            }
        }
        // WEST
        else if(startX - 1 >= 0){
            if(m[startX - 1][startY] != "B" && m[startX - 1][startY] != "▒" && m[startX - 1][startY] != "E" && m[startX - 1][startY] == " " && m[startX - 1][startY] != "\033[31m█\033[0m"){
                startX -= 1;
                m[startX + 1][startY] = "\033[31m█\033[0m";
                vector<int> xy = {startX, startY};
                aPath.push_back(xy);
            }
        }
        else if(m[startX][startY] == "E"){
            end = "E";
        } else {
            m[startX][startY] = "\033[31m█\033[0m";
            vector<int> xy = aPath.back();
            aPath.pop_back();
            startX = xy[0];
            startY = xy[1];
            m[startX][startY] = " ";
        }
        prnt(m);
    }
    allPaths.push_back(m);
}

int main(){
    cout << "\n\033[31m█\033[0m Path\n" << endl;
    vector<string> a = {"▒","B","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒"};
    vector<string> b = {"▒"," ","█"," "," "," ","█"," "," "," "," "," "," ","█"," "," "," "," "," "," "," ","█"," "," ","█","█","█","▒"};
    vector<string> c = {"▒"," "," "," ","█"," ","█"," ","█","█","█","█"," "," "," ","█","█","█","█","█"," ","█","█"," "," "," "," ","▒"};
    vector<string> d = {"▒","█","█","█","█"," ","█"," ","█","█"," ","█","█","█"," ","█"," ","█","█","█"," ","█","█","█","█"," ","█","▒"};
    vector<string> e = {"▒"," "," "," "," "," ","█"," "," "," "," ","█"," ","█","█","█"," ","█","█"," "," "," "," "," "," "," "," ","▒"};
    vector<string> f = {"▒"," ","█","█","█","█","█"," ","█","█","█","█"," "," "," "," "," "," ","█"," ","█","█","█","█","█","█"," ","▒"};
    vector<string> g = {"▒"," "," "," "," "," "," "," "," "," "," "," "," ","█","█","█","█"," ","█"," ","█"," ","█"," "," "," "," ","▒"};
    vector<string> h = {"▒","█"," ","█","█","█","█","█","█","█","█","█","█","█"," ","█","█"," ","█"," ","█"," ","█"," ","█","█","█","▒"};
    vector<string> i = {"▒"," "," ","█"," "," "," "," "," "," "," "," "," "," "," "," "," "," ","█"," "," "," ","█"," "," "," "," ","▒"};
    vector<string> j = {"▒","█","█","█"," ","█","█","█","█","█","█","█","█","█","█","█"," ","█","█","█","█","█","█","█","█","█"," ","▒"};
    vector<string> k = {"▒"," "," "," "," ","█"," "," "," "," "," "," "," "," "," "," "," ","█"," "," "," "," "," "," "," "," "," ","▒"};
    vector<string> l = {"▒","█","█","█"," ","█","█"," ","█"," ","█","█","█","█","█","█","█","█"," ","█","█","█","█","█","█","█","█","▒"};
    vector<string> m = {"▒","█"," ","█","█","█","█"," ","█"," ","█"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","▒"};
    vector<string> n = {"▒","█"," "," "," "," "," "," ","█"," ","█","█","█","█","█","█","█","█"," ","█","█","█","█","█","█"," ","█","▒"};
    vector<string> o = {"▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","▒","E","▒","▒"};
    vector<vector<string> > maze; maze.push_back(a); maze.push_back(b); maze.push_back(c); maze.push_back(d); maze.push_back(e);
    maze.push_back(f); maze.push_back(g); maze.push_back(h); maze.push_back(i); maze.push_back(j); maze.push_back(k);
    maze.push_back(l); maze.push_back(m); maze.push_back(n); maze.push_back(o);
    cout << "The Maze" << endl;
    prnt(maze);
    vector<vector<string> > tmp;

    tmp = cpy(maze);
    path(tmp);
    return 0;
}
