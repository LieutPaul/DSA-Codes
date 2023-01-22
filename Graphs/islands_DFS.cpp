#include<iostream>
#include<vector>
using namespace std;
void DFS(vector<vector<char>>&grid,int x,int y){
    if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size()){
        return ;
    }
    if(grid[x][y]=='1'){
        grid[x][y]='*';
        DFS(grid,x+1,y);
        DFS(grid,x-1,y);
        DFS(grid,x,y+1);
        DFS(grid,x,y-1);
    }
}
int numIslands(vector<vector<char>>& grid) {
    int islands=0,rows=grid.size(),cols=grid[0].size();
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(grid[i][j]=='1'){
                islands++;
                DFS(grid,i,j);
            }
        }
    }
    return islands;
}
