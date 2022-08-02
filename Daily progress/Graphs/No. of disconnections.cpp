/*
You are given an assignment to sort out the files of your department today.

A file contains various records. Each record has an (ID, Parent ID).

To make your task easier, you decided to separate records into different sets.

If a set contains a record with (ID, Parent ID) - (X, Y), then both X and Y must be present in the set.

There are A records. You are also given a 2D array B of dimensions N x 2,

where each row is record's (ID, Parent ID).



You have to find the maximum number of sets you can divide the records into.

A = 4
B = [1,2] [2,3] [3,4]
o/p: 1 
1 set is required only ...which contains 1,2,3,4 files

*/
int Solution::breakRecords(int A, vector<vector<int> > &B) {
    vector<int>adj[A+1];
    
    int ans =0;
    
    for(int i=0; i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    
    queue<int>q;

    vector<bool>visited(A+1,0);
  
    for(int i=1; i<=A;i++){
        q.push(i);
        
        if(visited[i]) continue;
        else{
        visited[i]=true;
        ans++;
        }
        
    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        for(auto v : adj[u]){
            if(!visited[v]){
                visited[v]=true;
                q.push(v);
            }
        }
    }
    }
   
    return ans;
}
