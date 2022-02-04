class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         vector<vector<string>>ans;
        unordered_map<string,vector<string>>mpp;
        int n=strs.size();
        for(int i=0;i<n;i++){
            string x=strs[i];
            sort(x.begin(),x.end());
            mpp[x].push_back(strs[i]);
        }
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};