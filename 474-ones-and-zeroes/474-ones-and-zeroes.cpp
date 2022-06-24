class Solution {
public:
    int solveRec(int ind,vector<vector<int>>&vec,int m,int n){
        if(ind==0){
            if(m>=vec[0][0] && n>=vec[0][1]) return 1;
            else return 0;
        }
        
        int notPick=solveRec(ind-1,vec,m,n);
        int pick=0;
        if(m>=vec[ind][0] && n>=vec[ind][1]) 
            pick=1+solveRec(ind-1,vec,m-vec[ind][0],n-vec[ind][1]);
        
        return max(pick,notPick);
        
        }
    int solveMemo(int ind,vector<vector<int>>&vec,int m,int n,vector<vector<vector<int>>>&dp){
        if(ind==0){
            if(m>=vec[0][0] && n>=vec[0][1]) return 1;
            else return 0;
        }
        if(dp[ind][m][n]!=-1) return dp[ind][m][n];
        int notPick=solveMemo(ind-1,vec,m,n,dp);
        int pick=0;
        if(m>=vec[ind][0] && n>=vec[ind][1]) 
            pick=1+solveMemo(ind-1,vec,m-vec[ind][0],n-vec[ind][1],dp);
        
        return dp[ind][m][n]=max(pick,notPick);
        
        }
    int solveTabu(vector<vector<int>>&vec, int m, int n){
    vector<vector<vector<int>>>dp(vec.size(),vector<vector<int>>(m+1,vector<int>(n+1,0)));
         
        for(int i=vec[0][0];i<=m;i++){
            for(int j=vec[0][1];j<=n;j++){
                dp[0][i][j]=1;
            }
        }
        
        for(int ind=1;ind<vec.size();ind++){
            for(int zeros=0;zeros<=m;zeros++){
                for(int ones=0;ones<=n;ones++){
                    
                       int notPick=dp[ind-1][zeros][ones];
                        int pick=0;
                        if(zeros>=vec[ind][0] && ones>=vec[ind][1]) 
                            pick=1+dp[ind-1][zeros-vec[ind][0]][ones-vec[ind][1]];

                         dp[ind][zeros][ones]=max(pick,notPick);
                }
            }
        }
        
        return dp[vec.size()-1][m][n];

    }
      int solveTabuSo(vector<vector<int>>&vec, int m, int n){
    vector<vector<int>>prev(m+1,vector<int>(n+1,0));
          vector<vector<int>>cur(m+1,vector<int>(n+1,0));
         
        for(int i=vec[0][0];i<=m;i++){
            for(int j=vec[0][1];j<=n;j++){
                prev[i][j]=1;
            }
        }
        
        for(int ind=1;ind<vec.size();ind++){
            for(int zeros=0;zeros<=m;zeros++){
                for(int ones=0;ones<=n;ones++){
                    
                       int notPick=prev[zeros][ones];
                        int pick=0;
                        if(zeros>=vec[ind][0] && ones>=vec[ind][1]) 
                            pick=1+prev[zeros-vec[ind][0]][ones-vec[ind][1]];

                         cur[zeros][ones]=max(pick,notPick);
                }
            }
            prev=cur;
        }
        
        return prev[m][n];

    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>vec;
        for(auto it:strs){
            int ones=0,zeros=0;
            for(auto itt:it){
                
                if(itt=='1')ones++;
                else zeros++;
            }
            vec.push_back({zeros,ones});
        }
        
       // return solveRec(vec.size()-1,vec,m,n);
        // vector<vector<vector<int>>>dp(vec.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        // return solveMemo(vec.size()-1,vec,m,n,dp);
        // return solveTabu(vec,m,n);
        return solveTabuSo(vec,m,n);
    }
};