class Solution {
public:
    int bs(vector<int>nums,int s,int e,int target){
        // int s=0,e=nums.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return -1;
    }
    int getPivot(vector<int>&nums){
        int s=0,e=nums.size()-1;
        while(s<e){
            int mid=s+(e-s)/2;
            if(nums[mid]>=nums[0]){
                s=mid+1;
            }else{
                e=mid;
            }
        }
        return s;
    }
    int search(vector<int>& nums, int target) {
        int pvt=getPivot(nums);
        int fs=bs(nums,0,pvt-1,target);
        int sc=bs(nums,pvt,nums.size()-1,target);
        return fs==-1?sc:fs;
    }
};