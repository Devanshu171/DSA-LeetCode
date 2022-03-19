// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map<string,int>mpp;
        int fst=0;
        string ans;
        for(int i=0;i<n;i++){
        mpp[arr[i]]++;
        fst=max(fst,mpp[arr[i]]);
        }
        int mx=0;
        for(int i=0;i<n;i++){
            if(mpp[arr[i]]<fst && mpp[arr[i]]>mx){
                mx=mpp[arr[i]];
                ans=arr[i];
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends