// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    bool isvalid(int x,int y,int n,int m,vector<vector<char>>& grid,vector<vector<int>>& vis){
        return (x>=0 && y>=0 && x<n && y<m && grid[x][y]=='1' && vis[x][y]==0);
    }
    void markIsland(int x,int y,vector<vector<char>>& grid,vector<vector<int>>& vis,int n,int m){
        vis[x][y]=1;
        int di[8]={0,0,1,-1,-1,-1,1,1};
        int dj[8]={1,-1,0,0,-1,1,1,-1};
        
        for(int i=0;i<8;i++){
            int newX=x+di[i];
            int newY=y+dj[i];   
            if(isvalid(newX,newY,n,m,grid,vis)){
                markIsland(newX,newY,grid,vis,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]=='1' && !vis[i][j]){
                        ans++;
                        markIsland(i,j,grid,vis,n,m);
                    }
                }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends