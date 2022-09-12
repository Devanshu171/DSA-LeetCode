class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        // unordered_map<int,int>mpp;
        // for(auto it:nums){
        //     mpp[it]++;
        // }
        // int ans=0;
        // for(auto it:mpp){
        //     cout<<it.first<<" "<<endl;
        //     if(k>0 && mpp.find(it.first+k)!=mpp.end() || k==0 && it.second>1 ) ans++;
        // }
        // return ans;
        sort(begin(nums),end(nums));
        int i=0,j=1,ans=0;
        
        for(;i<nums.size() && j<nums.size();){
            if(i==j || nums[j]-nums[i]<k){
                j++;
            }else{
                if(nums[j]-nums[i]==k){
                    ans++;
                    j++;
                    while(j<nums.size() && nums[j]==nums[j-1]) j++;
                }
                i++;
                while(i<nums.size() && nums[i]==nums[i-1]) i++;
            }
        }
        
        return ans;
        
    }
};