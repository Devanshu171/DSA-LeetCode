class Solution {
public:
    int bs(int start,int end,vector<int>&a,int k)
    {
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(a[mid]==k)
                return mid;
            else if(a[mid]>k)
                end=mid-1;
            else
                start=mid+1;
            
                
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int start=0;
        int end=n-1;
        if(nums[0]<=nums[n-1])
            return bs(0,n-1,nums,target);
        
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>nums[mid+1])
            {
                int first=bs(0,mid,nums,target);
                if(first!=-1)
                    return first;
                int second=bs(mid+1,n-1,nums,target);
                return second;
            }
            
            else if(nums[mid]>=nums[start])
                start=mid+1;
            else if(nums[mid]<nums[start])
                end=mid-1;
        }
        return -1;
    }
};