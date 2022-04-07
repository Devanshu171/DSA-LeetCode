// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
int solve(int ind, string s,unordered_set<string> &st)
{
  if (ind == s.size())
  {
    return 1;
  }

  for (int i = ind; i < s.size(); i++)
  {
    string sub = s.substr(ind, i - ind + 1);
    if (st.find(sub) != st.end())
    {
      if(solve(i + 1, s,st))
      return 1;
    }
  }
  return 0;
}
    int wordBreak(string A, vector<string> &dict) {
        //code here
  
        unordered_set<string>st;
        for(int i=0;i<dict.size();i++){
            st.insert(dict[i]);
        }
        return solve(0,A,st);
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends