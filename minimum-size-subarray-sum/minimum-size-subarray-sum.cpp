class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0,minlen=INT_MAX;
        int sum=0;
        while(j<n)
        {
            sum+=nums[j++];
            
            while(sum>=target)
            {
                minlen=min(minlen,j-i);
                sum-=nums[i++];
            }
        }
        
        if(minlen!=INT_MAX)
            return minlen;
        else 
            return 0;
            
    }
};