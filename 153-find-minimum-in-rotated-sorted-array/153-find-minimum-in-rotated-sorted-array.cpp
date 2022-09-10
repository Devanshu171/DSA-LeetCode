class Solution {
public:
    int findMin(vector<int>& nums) {

        int s=0,e=nums.size()-1;
        if(nums[0]<nums[nums.size()-1]) return nums[0];
        while(s<e){
            int mid=s+(e-s)/2;
            if(nums[0]<=nums[mid]) s=mid+1;
            else e=mid;
        }
        return nums[s];
    }
};