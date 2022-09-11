class Solution {
public:
    // #define mod 
    #define ll long long int
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
        vector<pair<int,int>>vec;
        priority_queue<int,vector<int>,greater<int>>pq;
 int mod=1e9+7;
        for(int i=0;i<n;i++){
            vec.push_back({eff[i],speed[i]});
        }
        sort(begin(vec),end(vec));
        ll speedSum=0;
        ll ans=0;
        for(int i=n-1;i>=0;i--){
            pq.push(vec[i].second);
            speedSum=(speedSum+vec[i].second);
            if(pq.size()>k){
                speedSum-=pq.top();
                 pq.pop();
            }
            ans=max(ans,(long long)speedSum*(long long)vec[i].first);
        }
        return ans%mod;
    }
};