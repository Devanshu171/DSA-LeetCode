class Solution {
public:
    void rev(int start,int end,vector<int>&arr)
    {
        while(start<end)
        {int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
         start++; end--;
        
        
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
                rev(0,n-1,nums);

        rev(0,k-1,nums);
        rev(k,n-1,nums);

    }
};