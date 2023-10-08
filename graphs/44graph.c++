//no of island
#include<iostream>
#include<vector>
using namespace std;

bool is_valid(int i,int j,int row,int col, vector<vector<bool>> &grid){
if(i>=0 && i< row && j>=0 && j<col&& grid[i][j]==1){
return true;

  }
  return false;
}


void num_icland_rec(int i,int j,int row,int col, vector<vector<bool>> &grid){

grid[i][j]=0;

if(is_valid(i+1,j,row,col,grid)){
    num_icland_rec(i+1,j,row,col,grid);
    }
if(is_valid(i,j+1,row,col,grid)){
    num_icland_rec(i,j+1,row,col,grid);
    }
if(is_valid(i-1,j,row,col,grid)){
    num_icland_rec(i-1,j,row,col,grid);
    }
if(is_valid(i,j-1,row,col,grid)){
    num_icland_rec(i,j-1,row,col,grid);
    }


}


int num_icland(vector<vector<bool>> &grid){

  int row=grid.size();
  int col=grid[0].size();
int ans=0;
for(int i=0;i<row;i++){
  for(int j=0;j<col;j++){
  
  if(grid[i][j]==1){
    ans++;
    num_icland_rec(i,j,row,col,grid);
  }
  }

    }
return ans;
}






int main(){

vector<vector<bool>> grid{{1,1,1,0,0,1},
                        {1,1,0,0,1,1},
                        {1,1,0,0,0,0},
                        {0,0,0,1,1,0}};

cout<<num_icland(grid);
}