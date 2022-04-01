// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
//   int l=0,r=0;
  int helper(int i,int p,int a[],int n,int k)
  {
      if(i==n){
          if(p<=k)
          return 1;
          else
          return 0;
      }
      if(p>k)
      return 0;
      
      int l=helper(i+1,p,a,n,k);
    //   temp.push_back(a[i]);
      int r=helper(i+1,p*a[i],a,n,k);
      return l+r;
      
  }
    int numOfSubsets(int arr[], int n, int k) {
        // vector<int>temp;
        return helper(0,1,arr,n,k)-1;
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>K;

        Solution ob;
        cout << ob.numOfSubsets(arr,N,K) << endl;
    }
    return 0;
}  // } Driver Code Ends