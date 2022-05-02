// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    #define ll long long 
    const int mod=1e9+7;
    long long int findMaxProduct(vector<int>&arr, int n){
        //Write your code here 
        int cntz=0,cntn=0,minn=INT_MIN;
        ll prdt=1;
        for(int i=0;i<n;i++){
            if(arr[i]==0)
            cntz++;
            else if(arr[i]<0){
                minn=max(minn,arr[i]);
            cntn++;
            }
            
            if(arr[i]!=0)
            prdt=(prdt*1ll*arr[i])%mod;
            
        }
        
        if(cntz==n)
        return 0;
        
        if(cntz==n-1 && cntz!=0 && cntn==1)
        return 0;
        if(cntn==1 && cntn==n)
        return prdt;
        if(cntn & 1){
            prdt/=minn;
        }
        return prdt;
    }
};



// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends