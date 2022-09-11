class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1)return 1;

        int maxReach=0;

        
        for(int i=0;i<nums.size()-1;i++){
            maxReach=max(maxReach,i+nums[i]);
     
                if(maxReach<=i) return 0;
               
        }
        return true;
    }
};