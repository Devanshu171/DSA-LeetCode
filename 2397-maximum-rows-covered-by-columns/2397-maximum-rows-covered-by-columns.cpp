class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        
        int n=mat.size(),m=mat[0].size();
        int ans=0;
        
        
        for(int i=0;i<(1<<m);i++){
            
            int cur=i,ones=0;
            vector<int>cols_taken(m,0);
            for(int j=0;j<m;j++){
                if(cur>>j & 1){
                    ones++;
                    cols_taken[j]=1;
                }
            }
            if(ones>cols)continue;
            
            int cur_ans=0;
            
            for(int i=0;i<n;i++){
                bool valid=true;
                for(int j=0;j<m;j++){
                     if(mat[i][j]==1 && cols_taken[j]!=1){
                         valid=false;
                         break;
                     }
                }
                cur_ans+=valid;
               
            }
            ans=max(ans,cur_ans);
                
        }
        return ans;
    }
};