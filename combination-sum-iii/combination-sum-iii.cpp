class Solution {
public:
    
    void helper(int ind,int k,int n,vector<int>&vec,vector<vector<int>>&ans)
    {
        if(vec.size()==k)
        {
            if(n==0)
            {
                ans.push_back(vec);
                // return;
            }
            // return;
        }
        
        for(int i=ind;i<=9 && i<=n && vec.size()<=k;i++)
        {
            vec.push_back(i);
            helper(i+1,k,n-i,vec,ans);
            vec.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>vec;
        vector<vector<int>>ans;
        helper(1,k,n,vec,ans);
        return ans;
    }
};