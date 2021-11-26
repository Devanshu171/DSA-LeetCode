class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>>q;
                vector<vector<int>> colored(n,vector<int>(m,0));

     int oc= image[sr][sc];
            image[sr][sc]=newColor;
        colored[sr][sc]=1;
        
        q.push({sr,sc});        
        int dx[]={-1,0,0,1};
        int dy[]={0,-1,1,0};
        
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
          
            
            for(int i=0;i<4;i++){
                int newX=x+dx[i];
                int newY=y+dy[i];
                if(newX>=0 && newX<n && newY>=0 && newY<m &&image[newX][newY]==oc && colored[newX][newY]!=1){
                    image[newX][newY]=newColor;
                    colored[newX][newY]=1;
                    q.push({newX,newY});
                }
            }
            
        }
        return image;
        
        
    }
};