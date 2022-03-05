class Solution {
public:
    void swap(int &a,int &b){
        int temp=a;
        a=b;
        b=temp;
    }
    void reverse(vector<int>&nums,int start,int end){
        while(start<end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return;
        int indx1=-1,indx2;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                indx1=i;
                break;
            }
        }
       if(indx1!=-1){ for(int i=n-1;i>=0;i--){
                if(nums[i]>nums[indx1]){
                    indx2=i;
                    break;
                }
        }
        
        swap(nums[indx1],nums[indx2]);}
        reverse(nums,indx1+1,n-1);
    }
};