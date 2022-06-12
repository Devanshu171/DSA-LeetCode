class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
       int totalSum=0,maxSum=INT_MIN,minSum=INT_MAX,sum1=0,sum2=0;
        for(int i=0;i<n;i++){
            sum1+=nums[i];
            sum2+=nums[i];
            totalSum+=nums[i];
            maxSum=max(maxSum,sum1);
            if(sum1<0) sum1=0;
            minSum=min(minSum,sum2);
            if(sum2>0) sum2=0;
            
        }
        
        if(totalSum==minSum){
            return maxSum;
        }
        return max(maxSum,totalSum-minSum);
        
        
    }
};