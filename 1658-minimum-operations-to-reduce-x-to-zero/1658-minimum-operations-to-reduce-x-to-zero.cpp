class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0,n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int len=-1;
        if(sum==x) return n;
        int target=sum-x;
        sum=0;
        int i=0,j=0;
        while(j<n){
            sum+=nums[j];
           while(i<j && sum>target){
               sum-=nums[i++];
           }
            if(sum==target){
                len=max(len,j-i+1);
            }
            j++;
        }
        return len==-1?-1:n-len;
    }
};