class Solution {
public:
    
    void helper(int i,int sum,int k,vector<int> &a,vector<vector<int>>&ans,vector<int>&ds  )
    {
        int n=a.size();
        if(sum>=k || i==n)
        {
            if(sum==k){
                ans.push_back(ds);
            return;}
            return;
        }
        
        
        if(a[i]<=k)
        {
            sum+=a[i];
            ds.push_back(a[i]);
            helper(i,sum,k,a,ans,ds);
            sum-=a[i];
            ds.pop_back();

        }
        helper(i+1,sum,k,a,ans,ds);
        
        
        
    }
    vector<vector<int>> combinationSum(vector<int>&a, int k) {
        vector<vector<int>>ans;
        vector<int>vec;
        helper(0,0,k,a,ans,vec);
            return ans;
    }
};