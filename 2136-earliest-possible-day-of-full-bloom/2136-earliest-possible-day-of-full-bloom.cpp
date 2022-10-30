class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>>vec;
        int n=plantTime.size();
        int sum=0;
        for(int i=0;i<n;i++){
            vec.push_back({growTime[i],plantTime[i]});
            sum+=plantTime[i];
        }
        sort(vec.begin(),vec.end(),greater<pair<int,int>>());
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=vec[i].second;
            sum-=vec[i].second;
            // cout<<vec[i].first<<" "<<vec[i].second<<" "<<sum<<" "<<ans<<endl;
            if(vec[i].first>sum){
                ans+=vec[i].first-sum;
                sum+=vec[i].first-sum;
            }
        }
        return ans;
    }
};