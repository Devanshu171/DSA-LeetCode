class Solution {
public:
    int solveRec(int i1,int j1,int i2,int j2,vector<vector<int>>& grid){
       if(i1>=grid.size() || j1>=grid.size() ||i2>=grid.size() || j2>=grid.size() || grid[i1][j1]==-1 || grid[i2][j2]==-1)
           return -1e8;
        if(i1==grid.size()-1 && j1==grid.size()-1 ) return grid[i1][j1];
       

        int maxi=-1e8;
        
         int dr=solveRec(i1+1,j1,i2,j2+1,grid);
         int rd=solveRec(i1,j1+1,i2+1,j2,grid);
         int rr=solveRec(i1,j1+1,i2,j2+1,grid);
         int dd=solveRec(i1+1,j1,i2+1,j2,grid);
        
        maxi=max({dd,rr,dr,rd});
        if(i1==i2 && j1==j2) maxi+=grid[i1][j1];
        else maxi+=grid[i1][j1]+grid[i2][j2];
        
        return maxi;
        
    }
     int solveMemo(int i1,int j1,int i2,int j2,vector<vector<int>>& grid,int n,int dp[51][51][51][51]){
         
       if(i1>=n || j1>=n ||i2>=n || j2>=n || grid[i1][j1]==-1 || grid[i2][j2]==-1)
           return -1e8;
        if(i1==n-1 && j1==n-1 ) return grid[i1][j1];
       if(dp[i1][j1][i2][j2]!=-1) return dp[i1][j1][i2][j2];

        int maxi=-1e8;
         
         int dr=solveMemo(i1+1,j1,i2,j2+1,grid,n,dp);
         int rd=solveMemo(i1,j1+1,i2+1,j2,grid,n,dp);
         int rr=solveMemo(i1,j1+1,i2,j2+1,grid,n,dp);
         int dd=solveMemo(i1+1,j1,i2+1,j2,grid,n,dp);
         
        maxi=max({dd,rr,dr,rd});
         
        if(i1==i2 && j1==j2) maxi+=grid[i1][j1];
        else maxi+=grid[i1][j1]+grid[i2][j2];
         
        return dp[i1][j1][i2][j2]= maxi;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int dp[51][51][51][51];
        memset(dp,-1,sizeof(dp));
        if(grid[0][0]==-1) return -1;
       // int ans= solveRec(0,0,0,0,grid);
       
        int ans=solveMemo(0,0,0,0,grid,n,dp);
         if(ans<0) return 0;
        return ans;
        
    }
};