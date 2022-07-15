//PLAIN RECURSION
//TIME COMPLEXITY - EXPONENTIAL
int sol(string a, string b, int m, int n){
    if(m==0||n==0) return 0;
    else{
        if(a[m-1]==b[n-1])
        return 1+sol(a, b, m-1, n-1);
        else
        return max(sol(a, b, m-1, n), max(sol(a, b,m, n-1)));
    }
}
int Solution::solve(string A, string B) {
    int a = A.size();
    int b = B.size();
    
    return sol(A,B,A.size(),B.size());
}


//MEMOIZATION
//TOP DOWN APPROACH
//TIME COMPLEXITY O(mn)
//SPACE COMPLEXITY theta(mn)
int sol(string a, string b, int m, int n, vector<vector<int>>&memo){
   if(memo[m][n]!=-1) return memo[m][n];
   
   if(m==0 || n==0) memo[m][n]=0;
   else{
   if(a[m-1]==b[n-1]) 
   memo[m][n]= 1+ sol(a,b,m-1,n-1,memo);
   else
    memo[m][n] = max(sol(a,b,m,n-1,memo), sol(a,b,m-1,n,memo));
   }
   
   return memo[m][n];
}
int Solution::solve(string A, string B) {
    int a = A.size();
    int b = B.size();
    
    vector<vector<int>>memo(a+1,vector<int>(b+1,-1));
   
    return sol(A,B,A.size(),B.size(), memo);
}


