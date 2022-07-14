//FLOOD FILL
//DFS

class Solution {
public:
    
   void dfs(vector<vector<int>>& image, int sr, int sc, int color,int m, int n, int k){
        
       if(image[sr][sc]==k){
        image[sr][sc]=color;
        
        if(sr>=0 && sr<m-1){
            dfs(image,sr+1,sc,color,m,n,k);
        }
        if(sr>0 && sr-1<m){
            dfs(image,sr-1,sc,color,m,n,k);
        } 
        if(sc>=0 && sc<n-1){
            dfs(image,sr,sc+1,color,m,n,k);
        } 
        if(sc>0 && sc-1<n){
             dfs(image,sr,sc-1,color,m,n,k);
        }
       }
        
       
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        
        
        if(image[sr][sc]!=color)
        dfs(image,sr,sc,color,m,n, image[sr][sc]);
        
        return image;
    }
};