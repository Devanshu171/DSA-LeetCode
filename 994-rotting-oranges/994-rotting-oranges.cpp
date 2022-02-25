class Solution {
public:
    struct node{
        int x,y,t;
        node(int _x,int _y,int _t){
            x=_x;
            y=_y;
            t=_t;
        }
    };
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<node>q;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push(node(i,j,0));
                } if(grid[i][j]!=0) cnt++;
            }
        }
        int orng=0;
        int ans=0;
        while(!q.empty()){
            
            int i=q.front().x;
            int j=q.front().y;
            int t=q.front().t;
            q.pop();
             orng++;
            ans=max(ans,t);
            int di[]={1,-1,0,0};
            int dj[]={0,0,1,-1};
            for(int k=0;k<4;k++){
                int col=i+di[k];
                int row=j+dj[k];
                if(col>=0 && col<n && row>=0 && row<m &&  grid[col][row]==1){
                   
                    grid[col][row]=2;
                    q.push(node(col,row,t+1));
                }
            }
        }
        cout<<cnt<<" "<<orng;
        if(cnt==orng) return ans;
        return -1;
    }
};