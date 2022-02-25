class Solution {
public:
    void dfs(int node,int target,vector<int>&temp,vector<vector<int>>&ans,vector<int>adj[]){
            temp.push_back(node);
        if(node==target){
            ans.push_back(temp);
        }else{
            for(auto it:adj[node]){
                dfs(it,target,temp,ans,adj);
            }
        }
        temp.pop_back();
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        int n=graph.size();
        vector<int>temp;
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){              
                adj[i].push_back(it);
            }
        }
        dfs(0,n-1,temp,ans,adj);
        
        
        return ans;
    }
};