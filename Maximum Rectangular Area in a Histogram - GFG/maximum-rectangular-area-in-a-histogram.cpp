// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    void NSR(long long arr[],vector<long long >&sr,int n){
        stack<long long>st;
        int k=n-1;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(st.empty()) sr[k--]=n;
            else sr[k--]=st.top();
            st.push(i);
        }
        // for(auto it:sr) cout<<it<<" ";
        // cout<<endl;
        return;
        
    }
    void NSL(long long arr[],vector<long long >&sl,int n){
        stack<long long>st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(st.empty()) sl.push_back(-1);
            else sl.push_back(st.top());
            st.push(i);
        }
        // for(auto it:sl) cout<<it<<" ";
        // cout<<endl;
        return;
        
    }
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<long long>sr(n),sl;
        NSR(arr,sr,n);
        NSL(arr,sl,n);
        long long maxArea=INT_MIN;
        for(int i=0;i<n;i++){
            long long area=(sr[i]-sl[i]-1)*arr[i];
            maxArea=max(maxArea,area);
        }
        return maxArea;
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