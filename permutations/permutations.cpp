class Solution {
public:
    
    void helper(vector<int>a,vector<int>&ds,vector<int>&vec,vector<vector<int>>&ans)
    {
        if(ds.size()==a.size())
        {
            ans.push_back(ds);
        }
        
        for(int i=0;i<a.size();i++)
        {
            if(vec[i]==0)
            {
                ds.push_back(a[i]);
                vec[i]=1;
                helper(a,ds,vec,ans);
                ds.pop_back();
                vec[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>ds;
        vector<int>vec(7,0);
        vector<vector<int>>ans;
        helper(nums,ds,vec,ans);
        return ans;
    }
};