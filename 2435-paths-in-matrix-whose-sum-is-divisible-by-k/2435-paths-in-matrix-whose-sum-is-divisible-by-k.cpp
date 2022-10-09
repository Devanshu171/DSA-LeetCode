class Solution {
public:
    long long int solve(int x,int y,int sum,vector<vector<int>>& grid, int k,vector<vector<vector<int>>>&dp,int &n,int &m){
        sum+=grid[x][y];
        if(x==n-1 && y==m-1){
            return sum%k==0;
        }
        
       
        if(dp[x][y][sum%k]!=-1) return dp[x][y][sum%k];
        int d=0,r=0;
        if(x+1<n){
            d=solve(x+1,y,sum,grid,k,dp,n,m);
        }
        if(y+1<m){
            r=solve(x,y+1,sum,grid,k,dp,n,m);
        }
        return dp[x][y][sum%k]= (d+r)%1000000007;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size(),sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=grid[i][j];
            }
        }
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(51,-1)));
            // vector<vector<map<int, int>>> dp(n,vector<map<int,int>>(m));

        return solve(0,0,0,grid,k,dp,n,m)%1000000007;
    }
};