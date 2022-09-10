class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for(auto it:nums) sum+=it;
        int sum2=0;
        for(int i=0;i<nums.size();i++){
            sum-=nums[i];
            if(sum2==sum) return i;
            sum2+=nums[i];
        }
        return -1;
    }
};