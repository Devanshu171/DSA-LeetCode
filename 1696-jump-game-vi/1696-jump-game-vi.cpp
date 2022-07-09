class Solution {
public:
    int solveRec(int ind,int &k,vector<int>&nums){
         
        if(ind==0) {
          
            return 0;
        }
        int ans=-1e8;
       
            for(int i=1;i<=k && ind-i>=0;i++){
                cout<<ind<<" "<<ind-i<<endl;
                ans=max(ans,solveRec(ind-i,k,nums)+nums[ind-i]);
            }
        return ans;
    }
    int solveMemo(int ind,int &k,vector<int>&nums,vector<int>&dp){
         
        if(ind==0) {
          
            return 0;
        }
        int ans=INT_MIN;
       if(dp[ind]!=INT_MIN) return dp[ind];
            for(int i=1;i<=k && ind-i>=0;i++){
                ans=max(ans,solveMemo(ind-i,k,nums,dp)+nums[ind-i]);
            }
        return dp[ind]=ans;
    }
    int solveTabu(vector<int>&nums,int k){
        int n=nums.size();
        vector<int>dp(n,INT_MIN);
        dp[0]=nums[0];
        for(int ind=1;ind<n;ind++){
                   
            for(int i=1;i<=k && ind-i>=0;i++){
                dp[ind]=max(dp[ind],dp[ind-i]+nums[ind]);
            }
        }
        return dp[n-1];
    }
     int solveTabuO(vector<int>&nums,int k){
        int n=nums.size();
        vector<int>dp(n,INT_MIN);
         deque<int>dq;
         dq.push_front(0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            if(dq.front()<i-k) dq.pop_front();
                   dp[i]=nums[i]+dp[dq.front()];
            while(!dq.empty() && dp[i]>=dp[dq.back()]) dq.pop_back();
            dq.push_back(i);           
        }
        return dp[n-1];
    }
    int maxResult(vector<int>& nums, int k) {
         int n=nums.size();
        // return solveRec(n-1,k,nums)+nums[n-1];
        // vector<int>dp(n,INT_MIN);
        // return solveMemo(n-1,k,nums,dp)+nums[n-1];
        // return solveTabu(nums,k);
        return solveTabuO(nums,k);

    }
};