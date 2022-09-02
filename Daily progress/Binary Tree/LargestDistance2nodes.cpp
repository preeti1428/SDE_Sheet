pair<int,int> farthestnode( unordered_map<int, vector<int>>&adj, int src, int n){
    int dis[n] = {INT_MAX};
    
    bool visited[n]={false};
    queue<int>q;
    
    q.push(src);
    dis[src]=0;
    
    int node;
   while(!q.empty()){
       int sr = q.front();
       q.pop();
       visited[sr]=true; 
       
           for(auto v: adj[sr]){
               if(!visited[v]){
                   visited[v]=true;
                   q.push(v);
                   
                   dis[v]= dis[sr]+1;
                   node = v;
               }
           }
   }
   return {node, dis[node]};
}


int Solution::solve(vector<int> &A) {
    unordered_map<int, vector<int>>adj;
    
    int n = A.size();
    int src ;
    
    for(int i=0;i<n;i++){
        if(A[i]!=-1){
            adj[A[i]].push_back(i);
            adj[i].push_back(A[i]);
        }
        else
        src=i;
    }
  
    if(n==1) return 0;
    
    pair<int,int>pp;
    
    pp = farthestnode(adj,src,n);
    pp = farthestnode(adj, pp.first,n);
    
    return pp.second;
 
}
