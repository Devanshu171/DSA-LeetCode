class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int n=matrix.size();
        int m=matrix[0].size();
        
        int i=0,j=m-1;
    
        while(i<=n-1 && j>=0)
        {
            int mid=matrix[i][j];
            
            if(mid==target)
                return true;
            else if(mid<target)
                    i++;
            else
                j--;
        }
        return false;
    }
};