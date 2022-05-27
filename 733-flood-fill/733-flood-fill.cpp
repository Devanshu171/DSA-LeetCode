class Solution {
public:
    void solve(vector<vector<int>>& image, int x, int y,int n,int m, int newColor,int prevColor){
        if(x<0 || x>=n || y<0 || y>=m || image[x][y]!=prevColor || newColor==prevColor) return;
        image[x][y]=newColor;
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        
        for(int i=0;i<4;i++){
            int newX=x+dx[i];
            int newY=y+dy[i];
            solve(image,newX,newY,n,m,newColor,prevColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size();
        int m=image[0].size();
        solve(image,sr,sc,n,m,newColor,image[sr][sc]);
        return image;
    }
};