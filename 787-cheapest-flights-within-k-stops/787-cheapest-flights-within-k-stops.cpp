class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        // int ans=0;
        
        vector<int>dist(n,INT_MAX),stop(n,INT_MAX);
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        
            pq.push({0,src,0});
            dist[src]=0;
            stop[src]=0;
       
            while(!pq.empty()){
               auto [curCost,curNode,curStop]=pq.top();
                pq.pop();
                
                if(curNode==dst){
                    return curCost;
                }
                    if(curStop>k)
                        continue;
                for(auto it:adj[curNode]){
                        int nextNode=it[0];
                       int  nextCost=curCost+it[1];
                    
                    if(nextCost<dist[nextNode] || curStop<stop[nextNode]){
                        dist[it[0]]=nextCost;
                        stop[it[0]]=curStop;
                        pq.push({nextCost,it[0],curStop+1});
                            
                    }
                }
        }
        
        return -1;
    }
};