class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        
        while(i<n)
        {
            if(nums[nums[i]-1]!=nums[i])
                swap(nums[nums[i]-1],nums[i]);
            else
                i++;
        }
        vector<int>vec;
        
        for(int j=0;j<n;j++)
        {
            if(nums[j]!=j+1)
            {
                vec.push_back(nums[j]);
                vec.push_back(j+1);
            }
        }
        return vec;
    }
};