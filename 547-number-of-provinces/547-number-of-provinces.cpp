class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<int>adj[]){
        
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& a) {
        int n=a.size();
        vector<int>adj[n];
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==1)
            adj[i].push_back(j);
            }
        }
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,vis,adj);
            }
        }
        return count;
    }
};