class Solution {
public:
    bool isValid(int i,int j,int n,int m,int color,vector<vector<int>>image){
        if(i>=0 && i<n && j>=0 && j<m && image[i][j]==color) return true;
        return false;
    }
    void fill(int i,int j,int n,int m,int newColor,int oldcolor,vector<vector<int>>&image){
        image[i][j]=newColor;
        int di[]={1,-1,0,0};
        int dj[]={0,0,-1,1};
        for(int k=0;k<4;k++){
            if(isValid(i+di[k],j+dj[k],n,m,oldcolor,image)){
                fill(i+di[k],j+dj[k],n,m,newColor,oldcolor,image);
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size();
        int m=image[0].size();
        if(image[sr][sc]!=newColor)
        fill(sr,sc,n,m,newColor,image[sr][sc],image);
        return image;
    }
};