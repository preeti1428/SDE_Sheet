// { Driver Code Starts

//QUESTION : Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges.
//Find the number of strongly connected components in the graph.
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void callacctotopo(vector<int>adjdup[], bool visit[],int s){
	    visit[s]=true;
	    
	    for(auto u : adjdup[s]){
	        if(visit[u]==false){
	            callacctotopo(adjdup,visit,u);
	        }
	    }
	   
	}
	
	void toposort(vector<int> adj[], bool visited[], stack<int>&s, int src){
	     visited[src]=true;
	     
	     for(auto v: adj[src]){
	         if(visited[v]==false)
	         toposort(adj,visited,s,v);
	         
	     }
	     s.push(src);
	     
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int>s;
        
        bool visited[V];
        for(int i=0; i<V;i++)
        visited[i]=false;
        
        
        //step1
        for(int i=0; i<V;i++){
            if(visited[i]==false)
            toposort(adj,visited,s,i);
            
        }
        
       
        
        //step2
        vector<int>adjdup[V];
        
        for(int i=0; i<V;i++){
            for(auto u : adj[i]){
                adjdup[u].push_back(i);
            }
        }
        
        //step3
        int ct = 0;
        bool visit[V];
        for(int i=0; i<V;i++)
        visit[i]=false;
        
        while(!s.empty()){
            int top = s.top();
            s.pop();
            
            if(visit[top]==false){
                ct++;
                callacctotopo(adjdup,visit,top);
            }
        }
        
        
        return ct;
        
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends