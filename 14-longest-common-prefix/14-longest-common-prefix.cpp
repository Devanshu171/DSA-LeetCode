class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        for(int i=1;i<strs.size();i++){
            int j=0;
            while(j<strs[i].size() && j<ans.size() && strs[i][j]==ans[j]) j++;
            if(j==0)
                return "";
            ans=ans.substr(0,j);
        }
        return ans;
    }
};