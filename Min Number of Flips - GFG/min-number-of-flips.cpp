// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int minFlips (string s)
{
    // your code here
    int c1=0,c2=0;
    for(int i=0;i<s.size();i++){
        if(i&1){
            if(s[i]=='0') c1++;
            else c2++;
        }else{
            if(s[i]=='0') c2++;
            else c1++;
        }
    }
    return min(c1,c2);
}