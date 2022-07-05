
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>>adj(A+1);
    vector<int>indeg(A+1,0);
    
    
    
    for(int i=0; i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
        indeg[B[i][1]]++;
    }
    
    queue<int>q;
    int ct = 0;
    
    for(int i=1;i<=A;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
         
        for(auto v : adj[u]){
            indeg[v]--;
            if(indeg[v]==0) q.push(v);
        }
        ct++;
    }
    //cout << ct << " ye h count";
    
    if(ct==A) return false;
    
    return true;
    
}

