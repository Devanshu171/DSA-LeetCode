class Solution {
public:
  bool  isValid(int i,int j,int n,int m,vector<vector<char>>&grid){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]=='1') 
            return true;
           else  
               return false;
    }
    
    void mark(int i,int j,int n,int m,vector<vector<char>>&grid){
        grid[i][j]='2';
        
        int di[]={-1,1,0,0};
        int dj[]{0,0,-1,1};
        
        for(int k=0;k<4;k++){
            if(isValid(i+di[k],j+dj[k],n,m,grid)){
                mark(i+di[k],j+dj[k],n,m,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    count++;
                    mark(i,j,n,m,grid);
                }
            }
                
        }
        return count;
    
    }
};