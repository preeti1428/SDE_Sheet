//RECURSION SIMPLE
// FROM N-1 TO 0 INDEX

int frog(int idx, vector<int>&heights,int ene){
    if(idx==1) return abs(heights[0]-heights[1]);
    if(idx==0) return 0;
    
    ene = frog(idx-1,heights,ene)+abs(heights[idx]-heights[idx-1]);
    ene = min(ene, frog(idx-2,heights,ene)+abs(heights[idx]-heights[idx-2]));
    
    return ene;
}
int frogJump(int n, vector<int> &heights)
{
    int ene=0;
    
    int ans = frog(n-1,heights,ene);
    return ans;
}


//MEMOIZATION
//SELF SMARTY SOLUTION
int frogJump(int n, vector<int> &h)
{
   int dp[n];
    
    dp[0]=0;
    dp[1] = abs(h[1]-h[0]);
    
    for(int i=2; i<n;i++){
        dp[i] = min(dp[i-2]+abs(h[i-2]-h[i]), dp[i-1]+abs(h[i-1]-h[i]));
    }
    return dp[n-1];
}
