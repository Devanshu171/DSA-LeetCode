class Solution {
public:
    void helper(int ind,int k,vector<int>&a,vector<int>&vec,vector<vector<int>>&ans)
    {
        if(k==0)
        {
            ans.push_back(vec);
            return;
        }
        
        for(int i=ind;i<a.size() && a[i]<=k ;i++)
        {
            if(i>ind && a[i]==a[i-1])
                continue;
            vec.push_back(a[i]);
            helper(i+1,k-a[i],a,vec,ans);
            vec.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& a, int k) {
        vector<int>vec;
        vector<vector<int>>ans;
        sort(a.begin(),a.end());
        helper(0,k,a,vec,ans);
        return ans;
        
    }
};