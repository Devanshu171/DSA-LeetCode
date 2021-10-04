class Solution {
public:
    int majorityElement(vector<int>& nums) {
         int count=1;
        int m=0;
        for(int i=1;i<nums.size();i++)
        {     if(nums[i]==nums[m])
                count++;
            else
                count--;
            if(count==0)
            {
                count=1;
                m=i;
            }
            
      
        
    }
      return nums[m];
    
    }
};