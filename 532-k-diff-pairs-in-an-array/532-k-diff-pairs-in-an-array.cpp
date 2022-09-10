class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        int ans=0;
        for(auto it:mpp){
            cout<<it.first<<" "<<endl;
            if(k>0 && mpp.find(it.first+k)!=mpp.end() || k==0 && it.second>1 ) ans++;
        }
        return ans;
        
    }
};