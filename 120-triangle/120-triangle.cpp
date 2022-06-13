class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                int left=0,right=0;
                if(i+1<n){
                   left= dp[i+1][j];                    
                }
                if(i+1<n && j+1<triangle[i+1].size()){
                    right=dp[i+1][j+1];
                }
                dp[i][j]= triangle[i][j]+min(left,right);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<triangle[i].size();j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        
        return dp[0][0];
    }
};