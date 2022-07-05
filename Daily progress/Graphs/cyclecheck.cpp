bool isCyclicBFS(int src, unordered_map<int,bool> &visited, unordered_map<int, vector<int>> &adj)
{
    unordered_map<int,int> parent;
    visited[src]=1;
    parent[src]=-1;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        for(auto neighbour: adj[front])
        {
            if(visited[neighbour] && parent[front]!=neighbour)
            {
                return 1;
            }
            else if(!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour]=1;
                parent[neighbour]=front;
            }
        }
    }
    return 0;
}

bool dfsrec(unordered_map<int,vector<int>>adj, unordered_map<int,bool>visited, int s, int parent){
     visited[s]= true;
     
     for(int u : adj[s]){
         if(visited[u]==false){
            bool cyc = dfsrec(adj, visited, u, s);
            if(cyc) return 1;
             
         }
         else if(u!=parent)
         return true;
     }
    
    return false;
}


int Solution::solve(int A, vector<vector<int> > &B) {
    
    
    unordered_map<int,vector<int>>adj;
      for(int i=0;i<B.size();i++)
    {
        int u=B[i][0];
        int v=B[i][1];
       
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
   
    unordered_map<int,bool> visited;
   
    for(int i=1;i<=A;i++)
    {
        if(!visited[i])
        {
            bool ans= isCyclicBFS(i,visited,adj);
            //bool ans=isCyclicDFS(i,-1,visited,adj);
            if(ans==1)
                return 1;
        }
    }
    return 0;
    
    /*
    unordered_map<int,bool>visited;
    for(int i=0; i<B.size();i++){
        int u = B[i][0];
        int v = B[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
   
        
    for(int i=1; i<=A;i++){
        if(visited[i]==false){
        bool bol = dfsrec(adj, visited, i, -1);
        
        if(bol) return true;
        }
    }
    return false;
    */
}