class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1;
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[res]==nums[i]) count++;
            else count--;
            if(count==0){
                count=1;
                res=i;
            }
        }
        int cnt=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==nums[res]) cnt++;
        }
        if(cnt>=nums.size()/2) return nums[res];
        else return -1;
    }
};