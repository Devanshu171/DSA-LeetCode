class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int i=0;
        int n=nums.size();
        
        while(i<n){
            if(nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }else{
                i++;
            }
        }
        for( i=0;i<n;i++){
            if(nums[i]!=i+1) return nums[i];
        }
        return 0;
    }
};