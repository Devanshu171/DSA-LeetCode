class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
        int first=0;
        int last =nums.size()-1;
        
        while(first<=last)
        {
            if(ans[0]!=-1 && ans[1]!=-1)
                break;
            if(nums[first]==target)
                ans[0]=first;
            
            if(nums[last]==target){
                ans[1]=last;
                // break;
            }
            
            if(nums[first]<target)
                first++;
            if(nums[last]>target)
                last--;
            
        }
        return ans;
        
        
        }
};