class Solution {
public:
    void solve(int ind, string s, vector<string> &ans, unordered_set<string> &st, string temp)
{
  if (ind == s.size())
  {
      temp.pop_back();
    ans.push_back(temp);
    return;
  }

  for (int i = ind; i < s.size(); i++)
  {
    string sub = s.substr(ind, i - ind + 1);
    if (st.find(sub) != st.end())
    {
      solve(i + 1, s, ans, st, temp+sub+' ');
    }
  }
}
    vector<string> wordBreak(string s, vector<string>& dict) {
         vector<string>ans;
        unordered_set<string>st;
        for(int i=0;i<dict.size();i++){
            st.insert(dict[i]);
        }
        solve(0,s,ans,st,"");
        return ans;
    }
};