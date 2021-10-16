class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int end=n-1;
        if(n==1)
            return nums[0];
        if(nums[start]<nums[end])
            return nums[start];
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            
            if(nums[mid]>nums[(mid+1)%n])
                return nums[mid+1];
            
            if(nums[mid]<nums[(mid-1+n)%n])
                return nums[mid];
            
            else if(nums[mid]>=nums[start])
                    start=mid+1;
            else if(nums[mid]<=nums[end])
                end=mid-1;
        }
        return 0;
    }
};