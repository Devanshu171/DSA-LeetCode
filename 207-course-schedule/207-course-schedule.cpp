class Solution {
public:
    bool check(int node,vector<int>&vis,vector<int>&visdfs,vector<int>adj[]){
        vis[node]=1;
        visdfs[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(check(it,vis,visdfs,adj))
                    return true;
            }else if(visdfs[it]==1){
                    return true;
            } 
        }
        visdfs[node]=0;
        return false;
    }
    bool canFinish(int v, vector<vector<int>>& arr) {
        
        vector<int>adj[v];
        vector<int>vis(v,0);
        vector<int>visdfs(v,0);
            
        for(auto it:arr){
            adj[it[0]].push_back(it[1]);
        }
        for(int i=0;i<v;i++){
            if(check(i,vis,visdfs,adj)) return false;
        }
        return true;
    }
};