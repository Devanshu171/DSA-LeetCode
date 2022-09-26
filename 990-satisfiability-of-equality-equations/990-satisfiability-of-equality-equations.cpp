class Solution {
public:
    
    void dfs(int i,vector<vector<int>>&adj,int col,vector<int>&vis,vector<int>&color){
        vis[i]=true;
        color[i]=col;
        for(auto it:adj[i]){
           if(!vis[it]) dfs(it,adj,col,vis,color);
        }
    }
    bool equationsPossible(vector<string>& equations) {
        vector<vector<int>>adj(26,vector<int>(2));
        vector<int>vis(26,0);
        vector<int>color(26,-1);
        
        for(auto it:equations){
            if(it[1]=='='){
                adj[it[0]-'a'].push_back(it[3]-'a');
                adj[it[3]-'a'].push_back(it[0]-'a');
            }
        }
        int col=1;
        for(int i=0;i<26;i++){
            if(!vis[i]) dfs(i,adj,col,vis,color);
            col++;
        }
        
        for(auto it:equations){
            if(it[1]=='!'){
            if(color[it[0]-'a']==color[it[3]-'a']) return false;
            }
        }
        return true;
    }
};