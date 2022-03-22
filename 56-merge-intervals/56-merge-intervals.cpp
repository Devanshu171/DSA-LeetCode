class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            return a[0]<b[0];
        });
        vector<int>cur=intervals[0];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=cur[1]){
                cur[1]=max(cur[1],intervals[i][1]);
            }else{
                ans.push_back(cur);
                cur=intervals[i];
            }
        }
        ans.push_back(cur);
        return ans;
    }
};