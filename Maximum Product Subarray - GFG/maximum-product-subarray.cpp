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
	    long long cur_prdt=1;
	    long long max_prdt=INT_MIN;
	    for(int i=0;i<n;i++){
	        cur_prdt*=arr[i];
	        if(cur_prdt==0){
	            cur_prdt=1;
	        }
	        max_prdt=max(max_prdt,cur_prdt);
	        
	    }
	      long long p=1;
	    long long m=INT_MIN;
	    for(int i=n-1;i>=0;i--){
	        p*=arr[i];
	        if(p==0){
	            p=1;
	        }
	        m=max(m,p);
	        
	    }
	    return max(m,max_prdt);
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