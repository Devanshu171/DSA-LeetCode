class Solution {
public:
    int solveRec(int row,int indx,vector<vector<int>>& triangle){
         if(indx<0 || indx==triangle[row].size()) return INT_MAX;
        if(row==0){
            return triangle[0][0];
        }
        
        int fs=solveRec(row-1,indx,triangle);
        int ss=solveRec(row-1,indx-1,triangle);
        
        return min(fs,ss)+triangle[row][indx];
        
    }
     int solveMemo(int row,int indx,vector<vector<int>>& triangle,vector<vector<int>>&dp){
         if(indx<0 || indx==triangle[row].size()) return INT_MAX;
        if(row==0){
            return triangle[0][0];
        }
        if(dp[row][indx]!=INT_MAX) return dp[row][indx];
        int fs=solveRec(row-1,indx,triangle);
        int ss=solveRec(row-1,indx-1,triangle);
        
        return dp[row][indx]= min(fs,ss)+triangle[row][indx];
        
    }
    int solveTabu(vector<vector<int>>& triangle){
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        dp[0][0]=triangle[0][0];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i+1;j++){
                int fs=INT_MAX;
                int ss=INT_MAX;
                 fs=dp[i-1][j];
                if(j>0)   ss=dp[i-1][j-1];
                
                dp[i][j]=min(fs,ss)+triangle[i][j];
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
         
        int ans=INT_MAX;
        int n=triangle.size();
        // for(int i=0;i<n;i++){
        //     ans=min(ans,solveRec(n-1,i,triangle));
        // }
        // return ans;
//         vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
  
//            for(int i=0;i<n;i++){
//             ans=min(ans,solveMemo(n-1,i,triangle,dp));
//         }
//         return ans;
        
        return solveTabu(triangle);
    }
};