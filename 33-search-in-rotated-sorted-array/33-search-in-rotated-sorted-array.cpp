class Solution {
public:
    int pivot(vector<int>&nums,int n){
        int start=0,end=n-1;
        if(nums[0]<=nums[n-1])
                return 0;
        while(start<=end){
            int mid=start+(end-start)/2;
            
            int next=nums[(mid+1)%n],prev=nums[(mid-1+n)%n];
            if(nums[mid]<=next && nums[mid]<=prev)
                return mid;
            else{
                if(nums[mid]<=nums[end])
                    end=mid-1;
                else if(nums[mid]>=nums[start]){
                    start=mid+1;
                }
            }
           
            
        }
         return -1;
    }
    int bs(vector<int>&nums,int start,int end,int x){
                
        // int start=0,end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==x)
                return mid;
            else if(nums[mid]>x)
                end=mid-1;
            else
                start=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int x) {
        int n=nums.size();
        int pvt=pivot(nums,n);
        int ans1=bs(nums,0,pvt-1,x);
        if(ans1!=-1)
            return ans1;
        else{
            return bs(nums,pvt,n-1,x);
        }
    }
};