// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool ispalin(string s){
      for(int i=0;i<s.size()/2;i++){
          if(s[i]!=s[s.size()-i-1])
          return false;
      }
      return true;
  }
  void solve(int ind,string s,vector<vector<string>>&ans,vector<string>temp){
      if(ind==s.size()){
        //   temp.pop_back();
          ans.push_back(temp);
          return;
      }
      for(int i=ind;i<s.size();i++){
          string sub=s.substr(ind,i-ind+1);
          if(ispalin(sub)){
              temp.push_back(sub);
              solve(i+1,s,ans,temp);
              temp.pop_back();
          }
      }
  }
    vector<vector<string>> allPalindromicPerms(string s) {
        // code here
        vector<vector<string>>ans;
        vector<string>temp;
        solve(0,s,ans,temp);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends