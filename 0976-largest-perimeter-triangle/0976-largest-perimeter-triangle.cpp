class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
      sort(nums.begin(),nums.end());
        int n=nums.size();
        while(n>=3){
             if(nums[n-1]+nums[n-2]>nums[n-3] && nums[n-1]+nums[n-3]>nums[n-2] && nums[n-2]+nums[n-3]>nums[n-1] ){
            return nums[n-1]+nums[n-2]+nums[n-3];
        }
            n--;
        }
        return 0;
       
    }
};