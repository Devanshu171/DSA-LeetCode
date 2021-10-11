class Solution {
public:
    void helper(int ind,vector<int>&a,vector<int>&vec,vector<vector<int>>&ans)
    {
        ans.push_back(vec);
               
        for(int i=ind;i<a.size();i++)
        {
            vec.push_back(a[i]);
            helper(i+1,a,vec,ans);
            vec.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>vec;
        vector<vector<int>>ans;
        // sort(nums.begin(),nums.end());
        
        helper(0,nums,vec,ans);
        return ans;
    }
};