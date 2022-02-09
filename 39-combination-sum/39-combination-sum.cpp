class Solution {
public:
    void helper(int ind,int sum,vector<int>&arr,vector<int>&temp,vector<vector<int>>&ans,int n){
                    
        if(ind==n){
            if(sum==0){
                ans.push_back(temp);
            }
            return;     
        }
        if(arr[ind]<=sum){
        temp.push_back(arr[ind]);
        helper(ind,sum-arr[ind],arr,temp,ans,n);
            temp.pop_back();   
        }
        helper(ind+1,sum,arr,temp,ans,n);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        helper(0,k,arr,temp,ans,arr.size());
        return ans;
        
    }
};