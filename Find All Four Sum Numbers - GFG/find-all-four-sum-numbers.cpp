// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>>ans;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-3;i++){
            int sum3=k-arr[i];
            for(int j=i+1;j<n-2;j++){
                int sum2=sum3-arr[j];
                int s=j+1,e=n-1;
                while(s<e){
                    int sum=arr[s]+arr[e];
                    if(sum>sum2){
                        e--;
                    }else if(sum<sum2) {
                        s++;
                    }else{
                        ans.push_back({arr[i],arr[j],arr[s],arr[e]});
                        while(s<e && arr[s]==arr[s+1]) s++;
                        while(s<e && arr[e]==arr[e-1])  e--;
                        s++;e--;
                    }
                }
                while(j<n-1 && arr[j]==arr[j+1]) j++;
            }
            while(i<n-1 && arr[i]==arr[i+1]) i++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends