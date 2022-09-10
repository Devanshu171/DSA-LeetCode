class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int n=matrix.size(),m=matrix[0].size();
        int count=0;
        int top=0,down=n-1,right=m-1,left=0;
        
        while(count<n*m){
            
            // cout<<top<<" "<<down<<" "<<right<<" "left<<endl;
            for(int i=left;i<=right && count<n*m;i++){
                cout<<top<<" "<<i<<endl;
                ans.push_back(matrix[top][i]);
                count++;
            }
            top++;
            for(int i=top;i<=down && count<n*m;i++){
                 cout<<i<<" "<<right<<endl;
                ans.push_back(matrix[i][right]);
                count++;
            }
            right--;
            for(int i=right;i>=left && count<n*m;i-- ){
                 cout<<down<<" "<<i<<endl;
                ans.push_back(matrix[down][i]);
                count++;
            }
            down--;
            for(int i=down;i>=top && count<n*m;i--){
                cout<<left<<" "<<i<<endl;
                ans.push_back(matrix[i][left]);
                count++;
            }
            left++;
        }
        return ans;
    }
};