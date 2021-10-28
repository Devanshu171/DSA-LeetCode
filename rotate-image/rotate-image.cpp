class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int n=a.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(a[i][j],a[j][i]);
            }
        }
           for(int i=0;i<n;i++){
        for(int j=0,k=n-1;j<k;j++,k--)
        {
            swap(a[i][j],a[i][k]);
            
        }
           }
    }
};