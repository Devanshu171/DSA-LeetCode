// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int countSquares(int N) {
        // code here
        int s=0,e=N,ans;
        
        while(s<=e){
            int mid=s+(e-s)/2;
            long long ele=mid*1LL*mid;
            // cout<<ele<<endl;
            if(ele<=N){
                ans=mid;
                s=mid+1;
            }else{
                e=mid-1;
            }
            
        }
        return ans*ans==N? ans-1:ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}  // } Driver Code Ends