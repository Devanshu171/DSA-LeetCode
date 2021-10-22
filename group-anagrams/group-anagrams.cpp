class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& a) {
        unordered_map<string,vector<string>>mpp;
        vector<vector<string>>ans;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            string x=a[i];
            sort(x.begin(),x.end());
            mpp[x].push_back(a[i]);
        }
        for(auto it:mpp)
            ans.push_back(it.second);
        
        return ans;
    }
};