/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 void adj(TreeNode* root, TreeNode* parent, unordered_map<int, vector<int>>&mp){
     vector<int>temp;
     
     if(root==NULL) return;
     
     if(parent!=NULL) temp.push_back(parent->val);
     if(root->left)
     temp.push_back(root->left->val);
     if(root->right)
     temp.push_back(root->right->val);
     
     mp[root->val]=temp;
     
     adj(root->left, root, mp);
     adj(root->right, root,mp);
     
 };
 
int burn(TreeNode* A, int B){
    unordered_map<int, vector<int>>mp;
    adj(A,NULL, mp);
    unordered_map<int,bool>vis;
    
    queue<int>q;
    int ct=0;
    q.push(B);
    
    while(!q.empty()){
        int sz = q.size();
        
        for(int i=0; i<sz;i++){
            int curr = q.front();
            vis[curr]=true;
            q.pop();
            
            for(auto it: mp[curr]){
                if(vis[it]==false)
                q.push(it);
            }
        }
        ct++;
    }
    return ct-1;
}

/*
int diameter(TreeNode* A, int B, int ans){
    
    if(A==NULL) return 0;
    int d1 = diameter(A->left, B, ans);
    int d2 = diameter(A->right, B, ans);
    
    int temp = 1+max(d1,d2);
    
    int res = max(temp, d1+d2+1);
}
*/

//get adjacents of nodes
//then bfs
int Solution::solve(TreeNode* A, int B) {
   
    return burn(A,B);
};
