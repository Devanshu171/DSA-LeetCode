// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
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
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        vector<string>ans;
        unordered_set<string>st;
        for(int i=0;i<dict.size();i++){
            st.insert(dict[i]);
        }
        solve(0,s,ans,st,"");
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends