class Solution {
public:
    	int findMaxSum(vector<int>&arr,int lo,int hi) {

	   int prev1=0,prev2=0;
	   for(int i=lo;i<=hi;i++){
	       
	       int withCur=arr[i]+prev2;
	       int withoutCur=prev1;
	       prev2=prev1;
	       prev1=max(withoutCur,withCur);
	   }
	   
	   return prev1;
	}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[1],nums[0]);
        return max(findMaxSum(nums,0,n-2),findMaxSum(nums,1,n-1));
    }
};