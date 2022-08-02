class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        if(n==1) return matrix[0][0];
        int row=n/k;
        
        priority_queue<int>pq;
        
        for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        pq.push(matrix[i][j]);
        if(pq.size()>k) pq.pop();
    }
        }

        return pq.top();
        
        
    }
};