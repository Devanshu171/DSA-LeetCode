class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        
        while(i<n){
            if(nums[i]<n && nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
            else{
                i++;
            }
        }
        return nums[n-1];
//         for(int i=0;i<n;i++){
            
//         }
    }
};