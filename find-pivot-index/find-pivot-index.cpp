class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int tsum=0;
        for(auto i:nums)
            tsum+=i;
        
        
        int i=0;
        int sum=0;
        while(i<n)
        {
            sum+=nums[i];
            if(tsum==sum)
                return i;
            tsum-=nums[i];
            i++;

            
        }
        return -1;
    }
};