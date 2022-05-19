// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    void nsl(int arr[],int n,vector<int>&left){
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) left.push_back(-1);
            else left.push_back(st.top());
            st.push(i);
        }
    }
    void nsr(int arr[],int n,vector<int>&right){
        stack<int>st;
        int k=n-1;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) right[k--]=n;
            else right[k--]=(st.top());
            st.push(i);
        }
    }
    vector <int> maxOfMin(int arr[], int n)
    {
      vector<int>left,right(n);
      nsl(arr,n,left);
      nsr(arr,n,right);
      
      vector<int>ans(n,-1);
      for(int i=0;i<n;i++){
          int len=right[i]-left[i]-2;
          ans[len]=max(ans[len],arr[i]);
      }
      
      
      for(int i=n-2;i>=0;i--){
          ans[i]=max(ans[i],ans[i+1]);
      }
      return ans;
      
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends