class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>ans;
      
        int top=0;
        int right=m-1;
        int bottom=n-1;
        int left=0;
        
        int count=0;
        int total=n*m;
        
        while(count<total){
            
            // left to right
            for(int i=left;count<total &&i<=right;i++){
                ans.push_back(matrix[top][i]);
                count++;
            }
            top++;
            // top to bottom
            for(int i=top;count<total &&i<=bottom;i++){
                ans.push_back(matrix[i][right]);
                 count++;
            }
            right--;
            // right to left
            for(int i=right;count<total &&i>=left;i--){
                ans.push_back(matrix[bottom][i]);
                 count++;
            }
            bottom--;
            // bottom to top
            for(int i=bottom;count<total &&i>=top;i--){
                ans.push_back(matrix[i][left]);
                 count++;
            }
            left++;
            
        }
        return ans;
    }
};