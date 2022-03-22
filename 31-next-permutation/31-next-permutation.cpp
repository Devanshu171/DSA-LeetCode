class Solution {
public:
    void reverse(vector<int>&arr,int i,int j){
        while(i<j){
            swap(arr[i++],arr[j--]);
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int indx1=-1,indx2;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                indx1=i;
                break;
            }
        }
        if(indx1!=-1){
            for(int i=n-1;i>=0;i--){
                if(nums[i]>nums[indx1]){
                    indx2=i;
                    break;
                }
            }
            swap(nums[indx1],nums[indx2]);
        }
        reverse(nums,indx1+1,n-1);
    }
};