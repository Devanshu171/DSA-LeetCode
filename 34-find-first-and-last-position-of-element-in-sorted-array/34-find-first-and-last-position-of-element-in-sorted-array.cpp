class Solution {
public:
    int first(vector<int>&nums, int x){
        int n = nums.size();
        int start=0,end=n-1;
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==x){
                ans=mid;
                end=mid-1;
            }
            else if(nums[mid]>x) end=mid-1;
            else start=mid+1;
        }
        return ans;
    }
        int last(vector<int>&nums, int x){
        int n = nums.size();
        int start=0,end=n-1;
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==x){
                ans=mid;
                start=mid+1;
            }
            else if(nums[mid]>x) end=mid-1;
            else start=mid+1;
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int fst=first(nums,target);
        int lst=last(nums,target);
        
         return {fst,lst};

    }
};