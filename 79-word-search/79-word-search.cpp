class Solution {
public:
     bool dfs(vector<vector<char> > &mat, string target,int x,int y,int count){
        if(count==target.size())
        return true;
        if(x<0 || x==mat.size() || y<0 || y==mat[0].size() || mat[x][y]!=target[count])
        return false;
        char temp=mat[x][y];
        mat[x][y]='0';
        bool found =false;
        count++;
        int di[]={1,-1,0,0};
        int dj[]={0,0,1,-1};
            for(int i=0;i<4;i++){
                int newX=x+di[i];
                int newY=y+dj[i];
                if(dfs(mat,target,newX,newY,count)){
                    found=true;
                    break;
                }
            }  
            mat[x][y]=temp;
            return found;
        
    }
    bool exist(vector<vector<char>>& mat, string target) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(mat,target,i,j,0))
                return true;
        }
        }
        return false;
    }
};