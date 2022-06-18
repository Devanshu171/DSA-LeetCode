class Solution {
public:
    int solveRec(int i,int j,vector<vector<int>>& triangle){
         
        if(i==triangle.size()-1){
            return triangle[i][j];
        }
        
        int fs=solveRec(i+1,j,triangle);
        int ss=solveRec(i+1,j+1,triangle);
        
        return min(fs,ss)+triangle[i][j];
        
    }
     int solveMemo(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>&dp){
        
        if(i==triangle.size()-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int fs=solveMemo(i+1,j,triangle,dp);
        int ss=solveMemo(i+1,j+1,triangle,dp);
        
        return dp[i][j]= min(fs,ss)+triangle[i][j];
        
    }
    int solveTabu(vector<vector<int>>& triangle){
        int n=triangle.size();
                vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                if(i==n-1) dp[i][j]=triangle[i][j];
                else{
                     // fs=INT_MAX,ss=INT_MAX;
                   int fs=dp[i+1][j];
                   int  ss=dp[i+1][j+1];
                        dp[i][j]=min(fs,ss)+triangle[i][j];
                }
            }
        }
        
        return dp[0][0];
    }
      int solveTabuSo(vector<vector<int>>& triangle){
        int n=triangle.size();
                vector<int>prev(triangle.back());
        for(int i=n-2;i>=0;i--){
            vector<int>cur(n,0);
            for(int j=i;j>=0;j--){
              

                   int fs=prev[j];
                   int  ss=prev[j+1];
                        cur[j]=min(fs,ss)+triangle[i][j];
            }
            prev=cur;
        }
        
        return prev[0];
    }
   
    int minimumTotal(vector<vector<int>>& triangle) {
         
   
        int n=triangle.size();

        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));

      // return solveRec(0,0,triangle);
        // return solveMemo(0,0,triangle,dp);
        // return solveTabu(triangle);
        return solveTabuSo(triangle);
    }
};