//Given a mtrix with 0 1 2 3 values
// 0 means blank wall
// 3 means blank cell
// 1 means source
// 2 means destination
//we have to tell if there exists a path from src to dest traversing through blank cells
// up down left right allowed


void dfs(vector<vector<int>>&A, int i, int j, int n, int m, int destx, int desty){
    
    if(i<0 || j<0 || i>=n || j>=m || A[i][j]==0) return;
    
    if(A[i][j]==2){
        A[i][j]=0;
        return;
    }
    
    A[i][j] = 0;
    
    dfs(A, i-1, j, n, m, destx, desty);
    
    dfs(A, i+1, j, n, m, destx, desty);
        
     dfs(A, i, j+1, n, m, destx, desty);
    
     dfs(A, i, j-1, n, m, destx, desty);
    
    
    return ;
}

//bfs approach can also be done using queue directional moves array
//moves = {{-1,0}, {0,-1}, {1,0}, {0,1}}

int Solution::checkPath(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    
    int srcx, srcy, destx, desty;
    bool l = false;
   
    for(int i=0; i<n;i++){
        for(int j = 0; j<m;j++){
            if(A[i][j]==1){
                srcx=i;
                srcy=j;
            }
            else if(A[i][j]==2){
                destx=i;
                desty=j;
            }
            //return (dfs(A,i-1,j,n,m,l) || dfs(A,i+1,j,n,m,l) || dfs(A,i,j-1,n,m,l) || dfs(A,i,j+1,n,m,l));
        }
    }
    
    dfs(A,srcx, srcy,n,m,destx, desty);
    
    if(A[destx][desty]==0) return true;
    
    return false;
}
