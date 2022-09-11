class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int maxE=-1;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            maxE=max(maxE,intervals[i][1]);
        }
        vector<int>time(maxE+2,0);
        
        for(int i=0;i<n;i++){
            time[intervals[i][0]]++;
            time[intervals[i][1]+1]--;
        }
        int ans=time[0];
    for(int i=1;i<time.size();i++){
        time[i]+=time[i-1];
        ans=max(ans,time[i]);
    }
        return ans;
    }
};