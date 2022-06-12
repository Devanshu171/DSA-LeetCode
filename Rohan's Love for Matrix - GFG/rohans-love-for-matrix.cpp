// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    int firstElement(int n) 
    {
        int prev2=0,prev1=1;
        for(int i=2;i<=n;i++){
          int  cur=(prev1+prev2)%1000000007;
            prev2=prev1;
            prev1=cur;
        }
        return prev1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n;
        cin >> n ;
        Solution ob;
        cout<<ob.firstElement(n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends