class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
     
        
       
        int ans=0,prev=0;
        int tank=startFuel;
        int n=stations.size();
        priority_queue<int>pq;
        
        for(int i=0;i<n;i++){
            // if(stations[i][0]>=target) break;
            tank-=stations[i][0]-prev;
            prev=stations[i][0];
  
            while(!pq.empty() && tank<0){
                tank+=pq.top();
                ans++;
                pq.pop();
            }
                if(tank<0){
                    return -1;
                }
            
            pq.push(stations[i][1]);
           
        }
        
        tank-=target-prev;         
            while(!pq.empty() && tank<0){
                tank+=pq.top();
                ans++;
                pq.pop();
            }
                if(tank<0){
                    return -1;
                }
        return ans;
    }
};