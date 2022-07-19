class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>hash;
        int maxi=0;
        int lasti=-1;
        for(int i=0;i<n;i++) hash.push_back(i);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        hash[i]=j;
                    }
                }
            }
            if(dp[i]>maxi){
                lasti=i;
                maxi=dp[i];
            }
        }
        
        vector<int>ans;
        ans.push_back(nums[lasti]);
        while(lasti!=hash[lasti]){
            lasti=hash[lasti];
            ans.push_back(nums[lasti]);
        }
        
        return ans;
    }
};