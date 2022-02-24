class Solution {
public:
    bool check(int node,vector<int>&vis,vector<int>&visdfs,vector<int>adj[]){
        vis[node]=1;
        visdfs[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(check(it,vis,visdfs,adj))
                    return true;
            }else if(visdfs[it]==1) return true;
        }
        visdfs[node]=0;
        return false;
    }
    void schedular(int node,vector<int>&ans,vector<int>&vis,vector<int>adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                schedular(it,ans,vis,adj);
            }
        }
        ans.push_back(node);
    }
    vector<int> findOrder(int n, vector<vector<int>>& arr) {
        vector<int>ans,vis(n,0),visdfs(n,0),adj[n];
        for(auto it:arr){
            adj[it[0]].push_back(it[1]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(check(i,vis,visdfs,adj))
                    return ans;
            }
        }
        stack<int>st;
        vector<int>vis1(n,0);
        for(int i=0;i<n;i++){
            if(!vis1[i]){
                schedular(i,ans,vis1,adj);
            }
        }
        // while(!st.empty()){
        // ans.push_back(st.top());
        //     st.pop();
        // }
        return ans;
        
    }
};