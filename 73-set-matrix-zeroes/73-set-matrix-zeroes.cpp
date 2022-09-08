class Solution {
public:
    void markZero(int x,int y,vector<vector<int>>& mat ){
        for(int i=0;i<mat.size();i++){
            mat[i][y]=0;
        }
         for(int i=0;i<mat[0].size();i++){
            mat[x][i]=0;
        }
    }
    void setZeroes(vector<vector<int>>& mat) {
        vector<pair<int,int>>zeros;
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    zeros.push_back({i,j});
                }
            }
        }
        
        for(int i=0;i<zeros.size();i++){
            markZero(zeros[i].first,zeros[i].second,mat);
        }
    }
};