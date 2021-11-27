class Solution {
public:
  
    vector<int> findOrder(int n, vector<vector<int>>& pq) {
       
        vector<int>indeg(n,0),ans;
        vector<int> adj[n+1];
        
        for(auto it:pq){
            adj[it[0]].push_back(it[1]);
        }
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0)
                    q.push(it);
            }
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==n) return ans;
        else return {};
     
    }
};