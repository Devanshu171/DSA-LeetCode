class Solution {
public:
    void helper(int ind,vector<int>&a,vector<int>&vec,vector<vector<int>>&ans)
    {
            ans.push_back(vec);
        
        for(int i=ind;i<a.size();i++){
            if(i>ind && a[i]==a[i-1]) continue;
            vec.push_back(a[i]);
            helper(i+1,a,vec,ans);
            vec.pop_back();
        }

        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        vector<int>vec;
        vector<vector<int>>ans;
        sort(a.begin(),a.end());
        helper(0,a,vec,ans);
        return ans;
        
    }
};