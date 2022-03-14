// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        // code here
        int len=1;
        int start=0;
        int n=s.size();
        int h,l;
            for(int i=0;i<n;i++){
                // for even
                l=i-1;
                h=i;
                while(l>=0 && h<n && s[l]==s[h]){
                    if(h-l+1>len){
                        len=h-l+1;
                        start=l;
                    }
                    l--;
                    h++;
                }
                //  for odd
                 l=i-1;
                h=i+1;
                while(l>=0 && h<n && s[l]==s[h]){
                    if(h-l+1>len){
                        len=h-l+1;
                        start=l;
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