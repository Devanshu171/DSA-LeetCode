class Solution {
public:
    void helper(vector<int>&a,int i,vector<int>&vec,vector<vector<int>>&ans)
    {
        int n=a.size();
        if(i==n)
        {
            ans.push_back(vec);
            return;
        }
        
        vec.push_back(a[i]);
        helper(a,i+1,vec,ans);
        vec.pop_back();
        helper(a,i+1,vec,ans);
        
    }
    vector<vector<int>> subsets(vector<int>& a) {
        vector<vector<int>>ans;
        vector<int>vec;
        helper(a,0,vec,ans);
        return ans;
    }
};