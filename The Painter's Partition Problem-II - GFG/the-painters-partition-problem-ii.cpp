// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  #define ll long long
  bool isvalid(int arr[],int n,int k,ll mb){
      int painters=1; int units=0;
      for(int i=0;i<n;i++){
         if(units+arr[i]>mb){
             painters++;
             units=arr[i];
         }else{
             units+=arr[i];
         }
      }
      return painters<=k;
  }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        
        ll low=0,high=0,ans=-1;
        for(int i=0;i<n;i++){
            high+=arr[i];
            if(low<arr[i]){
                low=arr[i];
            }
        }
        while(low<=high){
            ll mid=low+(high-low)/2;
            if(isvalid(arr,n,k,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends