class Solution {
public:
    int solveRec(int i,int j1,int j2,vector<vector<int>>& grid){

        if(j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size()) return INT_MIN;
        if(i==grid.size()-1){
            if(j1==j2) return grid[i][j2];
            else return grid[i][j1]+grid[i][j2];
        }
        
        int maxi=0;
        
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                int cur=solveRec(i+1,dj1+j1,dj2+j2,grid);
                if(j1==j2) cur+=grid[i][j1];
                else cur+=grid[i][j1]+grid[i][j2];
                maxi=max(maxi,cur);
            }
        }
        return maxi;
    }
    int solveMemo(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){

        if(j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size()) return INT_MIN;
        if(i==grid.size()-1){
            if(j1==j2) return grid[i][j2];
            else return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        
        int maxi=0;
        
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                int cur=solveMemo(i+1,dj1+j1,dj2+j2,grid,dp);
                if(j1==j2) cur+=grid[i][j1];
                else cur+=grid[i][j1]+grid[i][j2];
                maxi=max(maxi,cur);
            }
        }
        return dp[i][j1][j2]= maxi;
    }
     int solveTabu(vector<vector<int>>& grid){
         int n=grid.size();
         int m=grid[0].size();
         
vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,0)));
         
         for(int j1=0;j1<m;j1++){
             for(int j2=0;j2<m;j2++){
        if(j1==j2)    dp[n-1][j1][j2]=grid[n-1][j2];
            else dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];      
             }
         }
         
         for(int i=n-2;i>=0;i--){
             for(int j1=0;j1<m;j1++){
               for(int j2=0;j2<m;j2++){
                   
                        int maxi=0;
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                int cur=INT_MIN;
                if(dj1+j1<m && dj1+j1>=0 && dj2+j2<m && dj2+j2>=0 )
                 cur=dp[i+1][dj1+j1][dj2+j2];
                
                if(j1==j2) cur+=grid[i][j1];
                else cur+=grid[i][j1]+grid[i][j2];
                
                
                maxi=max(maxi,cur);
            }
        }
         dp[i][j1][j2]= maxi;
                   
               }
            }
        }
                    

         return dp[0][0][m-1];
     }
    int solveTabuSo(vector<vector<int>>& grid){
         int n=grid.size();
         int m=grid[0].size();
        
        // int front[m][m],curr[m][m];
        vector<vector<int>>front(m,vector<int>(m,0));
        vector<vector<int>>curr(m,vector<int>(m,0));
          
         for(int j1=0;j1<m;j1++){
             for(int j2=0;j2<m;j2++){
        if(j1==j2)    front[j1][j2]=grid[n-1][j2];
            else front[j1][j2]=grid[n-1][j1]+grid[n-1][j2];      
             }
         }
         
         for(int i=n-2;i>=0;i--){
             for(int j1=0;j1<m;j1++){
               for(int j2=0;j2<m;j2++){
                   
                        int maxi=0;
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                int cur=INT_MIN;
                if(dj1+j1<m && dj1+j1>=0 && dj2+j2<m && dj2+j2>=0 )
                 cur=front[dj1+j1][dj2+j2];
                
                if(j1==j2) cur+=grid[i][j1];
                else cur+=grid[i][j1]+grid[i][j2];
                
                
                maxi=max(maxi,cur);
            }
        }
         curr[j1][j2]= maxi;
                   
               }
            }
             front=curr;
        }
                    

         return front[0][m-1];
     }
         
    
    int cherryPickup(vector<vector<int>>& grid) {
        // return solveRec(0,0,grid[0].size()-1,grid);
        // vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
        // return solveMemo(0,0,grid[0].size()-1,grid,dp);
        // return solveTabu(grid);
        return solveTabuSo(grid);
    }
};