class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        vector<int>dist(n+1,INT_MAX);
        priority_queue<pair<int,int>>pq;
        
        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int dst=pq.top().first;
            pq.pop();
            
            for(auto it:adj[node]){
                int adjNode=it.first;
                int wt=it.second;
                
                if(dst+wt<dist[adjNode]){
                    dist[adjNode]=wt+dst;
                    pq.push({wt+dst,adjNode});
                }
            }
        }
        int totalDist=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX)
                return -1;
            totalDist=max(dist[i],totalDist);
        }
        return totalDist;
    }
};