class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
    
        int n=intervals.size();

        map<int,int>mpp;
        
        for(int i=0;i<n;i++){
            mpp[intervals[i][0]]++;
            mpp[intervals[i][1]+1]--;
        }
        int ans=0;
        int prev=0;
    for(auto it:mpp){
      
        prev+=it.second;
        ans=max(ans,prev);
    }
        return ans;
    }
};