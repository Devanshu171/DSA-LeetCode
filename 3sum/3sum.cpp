class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            
            int s=i+1;
            int target=-nums[i];
            int e=n-1;
            
            while(s<e)
            {
                int sum=nums[s]+nums[e];
                
                if(sum==target)
                {
                    ans.push_back(vector<int>{nums[i],nums[s],nums[e]});
                    while(s<e && nums[s]==nums[s+1])s++;
                    while(s<e && nums[e]==nums[e-1])e--;
                    s++; e--;
                }
                
                else if(sum>target)
                    e--;
                else
                    s++;
            }
            
            
        }
        
        return ans;
    }
};