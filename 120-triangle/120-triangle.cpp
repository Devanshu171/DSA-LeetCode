class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        
        vector<int>dp(triangle.back());
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
              
                dp[j]= triangle[i][j]+min( dp[j], dp[j+1]);
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<triangle[i].size();j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return dp[0];
    }
};