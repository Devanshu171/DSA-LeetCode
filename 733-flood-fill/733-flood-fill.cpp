class Solution {
public:
    bool isValid(int i,int j,int n,int m,int color,vector<vector<int>>image,vector<vector<int>>vis){
        if(i>=0 && i<n && j>=0 && j<m && image[i][j]==color && vis[i][j]==0) return true;
        return false;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        q.push({sr,sc});
        vis[sr][sc]=1;
        
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            int curColor=image[i][j];
            image[i][j]=newColor;
            int di[]={1,-1,0,0};
            int dj[]={0,0,1,-1};
            for(int k=0;k<4;k++){
                if(isValid(i+di[k],j+dj[k],n,m,curColor,image,vis)){
                    vis[i+di[k]][j+dj[k]]=1;
                    q.push({i+di[k],j+dj[k]});
                }
            }
        }
        return image;
    }
};