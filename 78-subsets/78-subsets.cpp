class Solution {
public:
  void helper(int ind,vector<int>&arr,vector<int>&temp,vector<vector<int>>&ans,int n){
                    
        if(ind==n){
                ans.push_back(temp);
             return;
            }
                
        temp.push_back(arr[ind]);
        helper(ind+1,arr,temp,ans,n);
        temp.pop_back();
         helper(ind+1,arr,temp,ans,n);
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>>ans;
        vector<int>temp;
        helper(0,arr,temp,ans,arr.size());
        return ans;
    }
};