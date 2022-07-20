//8-DIRECTION

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n, int area){
        
        if(i<0 || j<0 || i>=m || j>=n) return area;
        
        if(grid[i][j]==0) return area;
        
        grid[i][j]=0;
        
        
        return 1+dfs(grid, i-1,j,m,n, area)+dfs(grid, i+1,j,m,n, area)+dfs(grid, i,j-1,m,n, area)+dfs(grid, i,j+1,m,n, area)+
        dfs(grid, i-1,j-1,m,n, area)+dfs(grid, i-1,j+1,m,n, area)+dfs(grid, i+1,j-1,m,n, area)+dfs(grid, i+1,j+1,m,n, area);
        
    }
    
    
    int findMaxArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int res = INT_MIN;
        int area =0;
        
        for(int i=0; i<m;i++){
            for(int j=0; j<n;j++){
                if(grid[i][j]==1){
                    res = max(res, dfs(grid,i,j,m,n,area));
                }
                
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
