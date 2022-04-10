// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void solve(int ind,int k,string str,string &ans){

        ans=max(ans,str);
        if(k==0 || ind==str.size())
        return;
        char mxc=str[ind];
        for(int i=ind+1;i<str.size();i++){
            if(mxc<str[i])
            mxc=str[i];
        }
        if(mxc!=str[ind])
        k--;
        for(int i=str.size()-1;i>=ind;i--){
            if(str[i]==mxc){
                    swap(str[ind],str[i]);
                    solve(ind+1,k,str,ans);
                    swap(str[ind],str[i]);
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