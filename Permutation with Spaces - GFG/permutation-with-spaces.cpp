// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    
    void solve(int ind,string s ,vector<string>&ans,string temp){
        if(ind==s.size()){
            ans.push_back(temp);
            return;
        }
        temp+=" ";
        temp+=s[ind];
        solve(ind+1,s,ans,temp);
        temp.pop_back();
        temp.pop_back();
        temp+=s[ind];

        solve(ind+1,s,ans,temp);
    }
    vector<string> permutation(string s){
        // Code Here
        vector<string>ans;
        string temp="";
        temp+=s[0];
        solve(1,s,ans,temp);
        return ans;
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends