#include<iostream>
using namespace std;

void floodfill(int **maze, int row, int col, string psf, bool **visited,int n,int m)
{
    
    if(row < 0 || col < 0 || row >= n || col >= m || maze[row][col] == 1 || visited[row][col] == true)
    {
         return;
      }
      
      else if(row == n - 1 && col == m - 1)
      {
         cout<<psf<<endl;
         return;
      }
    
    visited[row][col] = true;
    floodfill(maze,row-1,col,psf+"t",visited,n,m);
    floodfill(maze,row,col-1,psf+"l",visited,n,m);
    floodfill(maze,row+1,col,psf+"d",visited,n,m);
    floodfill(maze,row,col+1,psf+"r",visited,n,m);
    visited[row][col] = false;
}

int main()
{
    int n,m;cin>>n>>m;
  int **arr;
    arr = new int *[n];
    for(int i = 0; i <n; i++)
    arr[i] = new int[m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
  bool **visited;
    visited = new bool *[n];
    for(int i = 0; i <n; i++)
    visited[i] = new bool[m];
    floodfill(arr,0,0,"",visited,n,m);
    
}
