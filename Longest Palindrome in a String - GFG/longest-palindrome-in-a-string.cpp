// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        // code here
        int start=0,len=1;
        for(int i=0;i<s.size();i++){
            int l=i-1,h=i+1;
            while(l>=0 && h<s.size() && s[l]==s[h]){
                if(len<h-l+1){
                    start=l;
                len=h-l+1;
                }
                l--;
                h++;
            }
            l=i-1,h=i;
            while(l>=0 && h<s.size() && s[l]==s[h]){
             if(len<h-l+1){
                    start=l;
                len=h-l+1;
                }
                l--;
                h++;
            }

        }
        return s.substr(start,len);
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends