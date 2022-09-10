class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n-2;i++){
            int s=i+1,e=n-1;
            
            while(s<e){
                int sum=nums[i]+nums[s]+nums[e];
                if(sum>0) e--;
                else if(sum<0) s++;
                if(sum==0){
                    ans.push_back({nums[i],nums[s],nums[e]});
                    while(s<e && nums[s]==nums[s+1]) s++;
                    while(s<e && nums[e]==nums[e-1]) e--;
                    s++;e--;
                }
            }
            while(i<n-2 && nums[i]==nums[i+1])i++;
        }
        return ans;
    }
};