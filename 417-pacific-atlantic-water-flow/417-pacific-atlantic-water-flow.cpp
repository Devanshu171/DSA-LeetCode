class Solution {
public:
    
    bool isValid(int x,int y,vector<vector<int>>&heights,vector<vector<int>>&vis,int lvl){
        return x>=0 && y>=0 && x<heights.size() && y<heights[0].size() && vis[x][y]==0 && heights[x][y]>=lvl;
    }
    
    void solve(int x,int y,vector<vector<int>>&heights,vector<vector<int>>&pac,vector<vector<int>>&vis){
        if(pac[x][y]) return ;
                pac[x][y]=true;
        vis[x][y]=true;
        int di[]={0,0,1,-1};
        int dj[]={-1,1,0,0};
        
        for(int i=0;i<4;i++){
            int newX=x+di[i],newY=y+dj[i];
            if(isValid(newX,newY,heights,vis,heights[x][y])){
                solve(newX,newY,heights,pac,vis);
            }
        }
        
        vis[x][y]=false;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>>pec(n,vector<int>(m,0));
        vector<vector<int>>ant(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            solve(i,0,heights,pec,vis);
            solve(i,m-1,heights,ant,vis);
        }
         for(int i=0;i<m;i++){
            solve(0,i,heights,pec,vis);
            solve(n-1,i,heights,ant,vis);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pec[i][j] && ant[i][j]) ans.push_back({i,j});
            }
        }
        
        return ans;
    }
};