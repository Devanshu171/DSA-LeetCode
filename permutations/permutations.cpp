class Solution {
public:
    
    void helper(int ind,vector<int>&a,vector<vector<int>>&ans)
    {
        if(ind==a.size())
        {
            ans.push_back(a);
            return;
        }
        
        for(int i=ind;i<a.size();i++)
        {
            swap(a[ind],a[i]);
            helper(ind+1,a,ans);
            swap(a[ind],a[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       
        vector<vector<int>>ans;
        helper(0,nums,ans);
        return ans;
    }
};