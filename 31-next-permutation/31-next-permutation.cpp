class Solution {
public:
    void swap(int &a,int &b){
        int temp=a;
        a=b;
        b=temp;
    }
    void reverse(vector<int>&nums,int s,int e){
        while(s<e){
            swap(nums[s],nums[e]);
            s++;
            e--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int indx1=-1,indx2;
        if(n<=1) return;
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
            // return nums;
        
    }
};