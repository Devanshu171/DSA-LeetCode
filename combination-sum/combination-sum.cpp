class Solution {
public:
    void helper(int i,int k ,vector<int>&a,vector<int>&vec,vector<vector<int>>&ans)
    {
        if(i==a.size())
        {
            if(k==0)
            {
                ans.push_back(vec);
                return;
            }
            return;
        }
        
        if(a[i]<=k)
        {
            vec.push_back(a[i]);
            helper(i,k-a[i],a,vec,ans);
            vec.pop_back();
        }
        helper(i+1,k,a,vec,ans);
           
    }
    vector<vector<int>> combinationSum(vector<int>& a, int k) {
        vector<int>vec;
        vector<vector<int>>ans;
        sort(a.begin(),a.end());
        helper(0,k,a,vec,ans);
        return ans;
    }
};