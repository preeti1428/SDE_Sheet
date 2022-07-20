//0->1->4
//0->2->1->4
//0->3->2->1->4

//NO NEED OF VISITED ARRAY

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    void dfs(int src, int dest, int &ct, vector<int>adj[]){
        
        if(src==dest){ ct++; return;}
      
        for(auto u : adj[src]){
            
            if(u==dest){
               ct++;
               return;
            }
            
                dfs(u,dest,ct,adj);
             
                
        }
        
        return;
        
    }
    
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        int ct=0;
        
       
        
        if(source==destination) ct++;
        
        for(auto u : adj[source]){
        dfs(u, destination,ct, adj);
        }
        
        return ct;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}  // } Driver Code Ends
