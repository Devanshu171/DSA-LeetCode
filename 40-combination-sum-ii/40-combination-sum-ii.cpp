class Solution {
public:
    void helper(int ind,int sum,vector<int>&arr,vector<int>&temp,vector<vector<int>>&ans)
    {
        if(sum==0){
            ans.push_back(temp);
            return; 
        }
        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>sum) break;
            
        temp.push_back(arr[i]);
        helper(i+1,sum-arr[i],arr,temp,ans);
        temp.pop_back();
        }
     
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int k) {
        vector<int>vec;
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        helper(0,k,arr,vec,ans);
        return ans;
        
    }
};