class Solution {
public:
    int missingNumber(vector<int>&nums) {
        sort(nums.begin(),nums.end());
        int i=0,n=nums.size();
        while(i<n)
        {
            if(i!=nums[i])
                return i;
            i++;
        }
        return n;
            
    }
};