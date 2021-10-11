class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxlen=1;
        int i=0;
        int j=1;
        int len=1;
        
        while(j<nums.size())
        {
            if(nums[j]>nums[i])
                len++;
            if(nums[j]<=nums[i])
            {
                len=1;
            }
            maxlen=max(len,maxlen);
            i++;j++;
        }
        return maxlen;
    }
};