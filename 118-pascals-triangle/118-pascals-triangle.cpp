class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        
        for(int i=0;i<n;i++){
            vector<int>vec;
            for(int j=0;j<=i;j++){
                if(j==0 || j==i) vec.push_back(1);
                else if(j>0 && j<i){
                    vec.push_back(ans[i-1][j]+ans[i-1][j-1]);
                } 
            }
            ans.push_back(vec);
        }
        return ans;
        
    }
};