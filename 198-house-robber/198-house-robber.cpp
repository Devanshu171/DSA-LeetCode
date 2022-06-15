class Solution {
public:
//     int  solve(vector<int> &arr,int n,vector<int>&dp){

//             if(n==0) return arr[n];
//                 if(dp[n]!=-1) return dp[n];
            
//             int fs=arr[n];
//             if(n>1){
//                 fs+=solve(arr,n-2 ,dp);
//             }
//             int ss=solve(arr,n-1,dp);
            
//             return dp[n]=max(fs,ss);
            
//         }
    int rob(vector<int>& nums) {
            int n=nums.size();
    
             // vector<int>dp(n,-1);   
        // return solve(nums,n-1,dp);
//            vector<int>dp(n,0);   
// 	   // return solve(arr,n-1,dp);
// 	   dp[0]=nums[0];
// 	   for(int i=1;i<n;i++){
	       
// 	       int withCur=nums[i];
	       
// 	       if(i>1) withCur+=dp[i-2];
// 	       int withoutCur=dp[i-1];
	       
// 	       dp[i]=max(withoutCur,withCur);
// 	   }
	   
	   // return dp[n-1];
        
         int prev1=nums[0],prev2;
	   for(int i=1;i<n;i++){
	       
	       int withCur=nums[i];
	       
	       if(i>1) withCur+=prev2;
	       int withoutCur=prev1;
	       prev2=prev1;
	       prev1=max(withoutCur,withCur);
	   }
	   
	   return prev1;
    }
};