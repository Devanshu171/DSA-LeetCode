// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends

class Solution{
    public:
    void solve(string s,int i,char prev,string &ans){
        if(i==s.size())
        return;
        if(s[i]!=prev)
        ans+=s[i];
        solve(s,i+1,s[i],ans);
    }
    string removeConsecutiveCharacter(string s)
    {
        string ans="";
        ans+=s[0];
        // solve(s,1,s[0],ans);
        
        for(int i=1;i<s.size();i++){
            if(s[i]!=s[i-1])
            ans+=s[i];
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 



  // } Driver Code Ends