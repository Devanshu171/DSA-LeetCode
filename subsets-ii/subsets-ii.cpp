class Solution {
public:
    void helper(vector<int>&a,int ind,vector<int>&vec,vector<vector<int>>&ans)
    {
        
        // draw recursive tree 
        int n=a.size();
         ans.push_back(vec);
            // return;
        
           for(int i=ind;i<n;i++){
               
           if(i>ind && a[i]==a[i-1])
               continue;
           vec.push_back(a[i]);
            helper(a,i+1,vec,ans);
            vec.pop_back();
               
           }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
      
    
    sort(a.begin(),a.end());
        vector<vector<int>>ans;
        vector<int>vec;
        helper(a,0,vec,ans);
        return ans;

    }
};