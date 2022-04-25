// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void solve(int ind,int k,string s,string &ans){
        if(s>ans){
            ans=s;
        }
        if(k==0 || ind==s.size())
        return;
        char ch=s[ind];
        
        for(int i=ind;i<s.size();i++){
            if(s[i]>ch){
                ch=s[i];
            }
        }
        if(ch!=s[ind])
        k-=1;
        
        for(int i=s.size()-1;i>=ind;i--){
            if(s[i]==ch){
                swap(s[ind],s[i]);
                solve(ind+1,k,s,ans);
                swap(s[ind],s[i]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans=str;
       solve(0,k,str,ans);
       return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends