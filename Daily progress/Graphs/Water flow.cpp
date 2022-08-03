/*
SAWAAL

Given an N x M matrix A of non-negative integers representing the height of each unit cell in a continent, the "Blue lake" touches the left and top edges of the matrix and the "Red lake" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the number of cells from where water can flow to both the Blue and Red lake.

Approach: Reverse Logic + Multisource BFS
*/

int n, m;

int dirx[4] = {1,-1,0,0};
int diry[4] = {0,0,1,-1};

void multibfs(vector<vector<int> > &A, queue<pair<int,int>>&q, vector<vector<bool>>&visited){
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        
        for(int i=0; i<4;i++){
            int newx = x+dirx[i];
            int newy = y+diry[i];
            
            if(newx<0 || newy<0 || newx>=n || newy>=m || visited[newx][newy]==true)
            continue;
            
            if(A[x][y]<=A[newx][newy]){
                q.push({newx,newy});
                visited[newx][newy]=true;
            }
        }
    }
    
}
int Solution::solve(vector<vector<int> > &A) {
    
    n =A.size();
    m = A[0].size();
    
    queue<pair<int,int>>qblue,qred;
    
    vector<vector<bool>>visited_blue(n,vector<bool>(m,false));
    vector<vector<bool>>visited_red(n,vector<bool>(m,false));
    
    int ans = 0;
    
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            if(i==0 || j==0){
            qblue.push({i,j});
            visited_blue[i][j]=true;
            }
            
            if(i==n-1 || j==m-1){
            qred.push({i,j});
            visited_red[i][j]=true;
            }
        }
    }
    multibfs(A,qblue,visited_blue);
    multibfs(A,qred,visited_red);
    
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            if(visited_blue[i][j] && visited_red[i][j])
            ans++;
        }
    }
    
    return ans;
}
