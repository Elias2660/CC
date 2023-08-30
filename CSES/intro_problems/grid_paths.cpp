/*
Recommended Compile Command: 
g++ -std=c++17 grid_paths.cpp 


TODO: FINISH PROBLEM
*/



//given the elements and their indicies calculate their possibilities
//its actually very possible to just simulate it ¯\_(ツ)_/¯
//actually not...
//there could actually be a recursive solution, where at a certain position, one could do all possible actions
//this will run a recursive algorithm with optimizations
    
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::find;
string path;
const vector<int> initial_pos = {0,0};
const vector<int> final_pos = {7,7};
const int R = 7, C = 7;
int count = 0;
vector<vector<int> > maze(R, vector<int> (C));

vector<char> find_possible_moves(vector<vector<int> > cur_maze, vector<int> cur_pos) {
    vector<char> possible_moves;

    //UP
    if(cur_pos[0]!=0 && cur_maze[cur_pos[0]-1][cur_pos[1]] != 1){
        possible_moves.push_back('U');
    }
    //DOWN
    if(cur_pos[0]!=R&&cur_maze[cur_pos[0]+1][cur_pos[1]] != 1) {
        possible_moves.push_back('D');
    }

    //LEFT
    if(cur_pos[1]!=0&&cur_maze[cur_pos[0]][cur_pos[1]-1]!=1) {
        possible_moves.push_back('L');
    }


    //RIGHT
    if(cur_pos[1]!=C&&cur_maze[cur_pos[0]][cur_pos[1]+1]!=1) {
        possible_moves.push_back('R');
    }
    return possible_moves;
}


void find_combinations(vector<vector<int> > cur_maze, vector<int> cur_pos, int move_num, String path) {
    //using a recursive function to perform brute force with optimizations
    char path_move = path[move_num];
    
    //EXIT CONDITION
    if (move_num==48  && cur_pos == {7,7}) {
        count++;
    }
    vector<char> possible_moves = find_possible_moves(cur_maze, cur_pos);

    if (path[move_num] == '?') {
        //if the move is indeterminate
        
    } else if (find(possible_moves.begin(), possible_moves.end(), path_move) == possible_moves.end() ) {
        
    }

    
}

int main() {
    cin >> path;
    //initializing the maze
    find_combinations(maze, initial_pos, 0, path);

    cout << count << endl;
}
