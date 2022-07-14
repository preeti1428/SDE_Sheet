//NO OF ISLANDS
//DFS

class Solution {
public:
    
    void dfs(vector<vector<bool>>&visited, vector<vector<char>>&grid, int i, int j){
            if(grid[i][j]=='1'){
             visited[i][j]=1;
             
             if(i>=1 && !visited[i-1][j]) dfs(visited,grid,i-1,j);
             if(j>=1 && !visited[i][j-1]) dfs(visited,grid,i,j-1);
             if(i+1 < grid.size() && !visited[i+1][j]) dfs(visited, grid, i+1,j);
             if(j+1< grid[0].size() && !visited[i][j+1]) dfs(visited, grid, i, j+1);
            }
        else{
            visited[i][j]=1;
        }
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int ct=0;
        
        vector<vector<bool>>visited(m, vector<bool>(n,0));
        
        for(int i=0; i<m;i++){
            for(int j=0; j<n;j++){
                if(visited[i][j]==false && grid[i][j]=='1'){
                    dfs(visited,grid,i,j);
                    ct++;
                }
            }
        }
        
        return ct;
    }
};



//WITHOUT VISITED ARRAY
//CPP
class Solution {
public:
    void DFS(vector<vector<char>>& g, int i, int j, int n, int m) {
		// checking if we are in any invalid cell, either out of matrix or cell value is zero
        if(i<0 or j<0)  return;
        if(i>=n or j>=m)    return;
        if(g[i][j]=='0')    return;
        
		// marking the current cell to zero
        g[i][j]='0';
        
		// calling dfs for adjacent cells to check the connected cells in four directions
        DFS(g,i+1,j,n,m);
        DFS(g,i,j+1,n,m);
        DFS(g,i-1,j,n,m);
        DFS(g,i,j-1,n,m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        int n=grid.size(), m=grid[0].size();
		// traverse the grid and count how many times dfs is being run
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1'){
                    res++;
                    DFS(grid,i,j,n,m);
                }
            }
        }
        return res;
    }
};