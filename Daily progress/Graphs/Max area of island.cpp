class Solution {
public:
    
    int dfs(vector<vector<int>>& grid, int m, int n, int i, int j, int area){
         if(i<0 || j<0 || i>=m || j>=n) return area;
         if(grid[i][j]==0) return area;
         
         grid[i][j]=0;
        
         //area = 1+ dfs(grid,m,n,i-1,j,area);
        //area = 1 + dfs(grid,m,n,i+1,j,area);
        //area = 1 + dfs(grid,m,n,i,j+1,area);
        //area = 1 + dfs(grid,m,n,i,j-1,area);
        
        return 1+dfs(grid,m,n,i-1,j,area)+dfs(grid,m,n,i+1,j,area)+dfs(grid,m,n,i,j+1,area)+dfs(grid,m,n,i,j-1,area);
        
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int area = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    int k = dfs(grid,m,n,i,j,0);
                    area = max(area,k);
                }
            }
        }
        
        //return (area)/4;
        return area;
        
    }
};