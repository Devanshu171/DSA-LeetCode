class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        
        while(i<n){
            if(nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
            else
                i++;
        }
        vector<int>ans;
        for(int j=0;j<n;j++){
            if(nums[j]!=j+1)
                ans.push_back(j+1);
        }
        return ans;
    }
};