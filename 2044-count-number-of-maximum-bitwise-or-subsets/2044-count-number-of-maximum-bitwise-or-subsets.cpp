class Solution {
public:
    int solve(int ind,vector<int>&nums,int target,int Or){
        if(ind==nums.size()){
            return Or==target;
        }
        int a=solve(ind+1,nums,target,Or|nums[ind]);
        int b=solve(ind+1,nums,target,Or);
        return a+b;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int mOR=0;
        for(auto it:nums) mOR|=it;
       return solve(0,nums,mOR,0);
    }
};