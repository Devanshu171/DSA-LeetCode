// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long p1=1;
	    long long p2=1;
	    long long max_prdt=INT_MIN;
	    for(int i=0;i<n;i++){
	        p1*=arr[i];
	        p2*=arr[n-i-1];
	        if(p1==0){
	            p1=1;
	        }
	        if(p2==0){
	            p2=1;
	        }
	        max_prdt=max(max_prdt,max(p1,p2));
	        
	    }
	    return max_prdt;

	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends