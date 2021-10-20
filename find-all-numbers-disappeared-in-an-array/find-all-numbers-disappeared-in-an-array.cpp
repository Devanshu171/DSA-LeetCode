class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        vector<int>vec;
        while(i<n)
        {
            if(nums[nums[i]-1]!=nums[i] )
                swap(nums[i],nums[nums[i]-1]);
            else 
                i++;
                
        }
        
        for(int j=0;j<n;j++)
        {
            if(nums[j]!=j+1)
                vec.push_back(j+1);
        }
        
        return vec;
    }
};