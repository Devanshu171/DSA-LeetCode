class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        // for(int i=0;i<n;i++){
        //     int j=i+1;
        //     while(j<n && j<=i+k){
        //         if(nums[j++]==nums[i]) return true;
        //     }
        // }
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            if(mpp.find(nums[i])!=mpp.end()){
               
                if(i-mpp[nums[i]]<=k) return true;
            }
            mpp[nums[i]]=i;
        }
        return false;
    }
};