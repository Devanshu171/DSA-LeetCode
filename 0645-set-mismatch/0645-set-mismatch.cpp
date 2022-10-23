class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        
        while(i<n){
            if(nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
            else{
                i++;
            }
        }
        vector<int>ans;
        for(int k=0;k<n;k++){
            if( nums[k]!=k+1){
                ans.push_back(nums[k]);
                ans.push_back(k+1);

            }
        }
        return ans;
    }
};