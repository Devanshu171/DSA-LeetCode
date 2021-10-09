class Solution {
public:
    void helper(vector<int>&a,int i,int k,vector<int>vec,vector<vector<int>>&ans)
    {
        // draw a recursion tree to understand
        int n=a.size();
        if(i==n)
        {
            if(k==0){
                ans.push_back(vec);
            return;}
            
            return;    
        }
        
        if(a[i]<=k)
        {
            k-=a[i];
            vec.push_back(a[i]);
            helper(a,i,k,vec,ans);
            vec.pop_back();
            k+=a[i];
        }
        helper(a,i+1,k,vec,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& a, int k) {
        vector<vector<int>>ans;
        vector<int>vec;
        helper(a,0,k,vec,ans);
        return ans;
    }
};