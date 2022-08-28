class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
//         vector<vector<int>>ans(n,vector<int>(m,0));
        
//             for(int j=0;j<m;j++){
//                 map<int,int>mpp;
//                 int s=0,e=j;
//                 int count=0;
//                 while(s<n && e<m){
//                     mpp[mat[s][e]]++;
//                     count++;
//                     s++;
//                     e++;
//                 }
//                 s=0,e=j;
//                 for(auto it:mpp){
//                     while(it.second--){
//                         mat[s++][e++]=it.first;
                        
//                     }
//                 }
//             }
//         for(int i=1;i<n;i++){
//              map<int,int>mpp;
//                 int s=i,e=0;
//                 int count=0;
//                 while(s<n && e<m){
//                     mpp[mat[s][e]]++;
//                     count++;
//                     s++;
//                     e++;
//                 }
//                 s=i,e=0;
//                 for(auto it:mpp){
//                     while(it.second--){
//                         mat[s++][e++]=it.first;
                        
//                     }
//                 }
//         }
        
//         return mat;
        
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>>mpp;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mpp[i-j].push(mat[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat[i][j]=mpp[i-j].top(); mpp[i-j].pop();
            }
        }
        
        return mat;
    }
};