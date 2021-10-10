class Solution {
public:
    
    void helper(int ind,int n,int k, vector<int>&vec,vector<vector<int>>&ans)
    {
        if(vec.size()==n && k==0)
        {
            ans.push_back(vec);
            return;
        }
        if(k<0) return;
        
        
        for(int i=ind;i<10 && i<=k;i++ )
        {
            vec.push_back(i);
            helper(i+1,n,k-i,vec,ans);
            vec.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum3(int n, int k) {
            vector<int>vec;
        vector<vector<int>>ans;
        helper(1,n,k,vec,ans);
        return ans;
    }
};