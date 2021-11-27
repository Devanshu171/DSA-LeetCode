class Solution {
public:
    
    bool checkcycle(int node,vector<int>&vis,vector<int>&dfspath,vector<int>adj[]){
        vis[node]=1;
        dfspath[node]=1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                if(checkcycle(it,vis,dfspath,adj))
                    return true;
            }
            else if(vis[it]==1 && dfspath[it]==1)
                return true;
        }
        dfspath[node]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pq) {
        vector<int>vis(n+1,0);
        vector<int>dfspath(n+1,0);
        vector<int>adj[n+1];
        
        for(auto it:pq){
            adj[it[0]].push_back(it[1]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(checkcycle(i,vis,dfspath,adj))
                    return false;
            }
        }
        return true;
    }
};