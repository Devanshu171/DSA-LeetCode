// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    #define ll long long
    void nsl(ll arr[],int n,vector<ll>&left){
        
        stack<ll>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(st.empty()) left.push_back(-1);
            else left.push_back(st.top());
            st.push(i);
        }
    }
    void nsr(ll arr[],int n,vector<ll>&right){
         stack<ll>st;
         int m=n-1;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(st.empty()) right[m--]=n;
            else right[m--]=st.top();
            st.push(i);
        }
    }
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<ll>left,right(n);
        nsl(arr,n,left);
        nsr(arr,n,right);
        
        ll ans=0;
        
        for(int i=0;i<n;i++){
            ll area=arr[i]*(right[i]-left[i]-1);
            
            ans=max(area,ans);
        }
        return ans;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends