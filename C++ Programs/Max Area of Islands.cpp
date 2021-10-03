/* Given the n x m grid with values 0 and 1, where 1 is trated as island and 0 as water.
  We need to find the maximum area of adjacent islands possible in the whole grid (considering all 4 directions and not in diagonal directions).
  For Eg:
  INPUTS
  n = 5
  m = 5
  Grid:
  1 0 0 0 1
  0 1 0 1 1
  1 0 0 1 1
  0 0 0 1 1
  1 0 1 0 0 
  OUTPUT
  Maximum island area possible in grid is: 7 
  Reason: 7 adjacent islands is the max area of 1s in the given grid
*/

#include<bits/stdc++.h>
using namespace std;

// v => keep track of visited places
// x & y => current tracked index
// sum => cumulatively keeps track of number of adjacent islands for a patch of islands
void dfs(int x,int y, vector<vector<int>>  &v, vector<vector<int>> &grid, int &sum) {
    if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || v[x][y] == 1 || grid[x][y] == 0)
        return;

    sum++;
    v[x][y] = 1;

    dfs(x+1, y, v, grid, sum);
    dfs(x-1, y, v, grid, sum);
    dfs(x, y+1, v, grid, sum);
    dfs(x, y-1, v, grid, sum);
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxi = 0, sum = 0;
    vector<vector<int>> v(grid.size(), vector<int> (grid[0].size(), 0));

    for(int i=0;i<grid.size();i++) {
        for(int j=0;j<grid[0].size();j++) {
            if(v[i][j] == 0 && grid[i][j] != 0) {
                dfs(i, j, v, grid, sum);

                maxi = max(maxi, sum);
                sum = 0;
            }
        }
    }

    return max(maxi, sum);
}

int main()
{
    int n,m;

    cout<<"Enter n and m:";
    cin>>n>>m;

    cout<<"\nEnter the grid values:";

    vector<vector<int>> arr(n, vector<int>(m)); // Initializing n x m grid

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];

    cout<<"\nMaximum island area possible in grid is: "<<maxAreaOfIsland(arr);
}
