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
//     int solveTabu(vector<vector<int>>& triangle){
//         int n=triangle.size();
//                 vector<vector<int>>dp(n,vector<int>(n,0));
//         for(int i=n-1,i>=0;i--){
//             for(int j=0;j<i+1,j++){
//                 if()
//             }
//         }

        
        
//     }
   
    int minimumTotal(vector<vector<int>>& triangle) {
         
   
        int n=triangle.size();

        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));

      // return solveRec(0,0,triangle);
        return solveMemo(0,0,triangle,dp);
    }
};