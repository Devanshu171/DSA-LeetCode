class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int n=matrix.size(),m=matrix[0].size();
        
        for(int i=m-1;i>=0;i--){
            int k=i,j=0;
            int ele=matrix[j][k];
            while(k<m && j<n){
                if(matrix[j][k]!=ele) return false;
                j++;k++;
            }
        }
        for(int i=1;i<n;i++){
            int k=0,j=i;
             int ele=matrix[j][k];
             while(k<m && j<n){
                if(matrix[j][k]!=ele) return false;
                j++;k++;
            }
        }
        return true;
    }
};