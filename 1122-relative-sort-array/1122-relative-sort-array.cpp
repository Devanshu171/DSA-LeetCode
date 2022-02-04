class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mpp;
        int n=arr1.size();
        int m=arr2.size();
        for(int i=0;i<n;i++){
            mpp[arr1[i]]++;
        }
        vector<int>ans;
        for(int i=0;i<m;i++){
            while(mpp[arr2[i]]--){
                ans.push_back(arr2[i]);
            }
            
        }
        for(auto it:mpp){
            if(it.second>0){
                while(it.second--) ans.push_back(it.first);
            }
        }
        return ans;
    }
};