// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  bool ifpossible(int arr[],int n,int k,long long mx){
      long int painter=1;
      long long units=0;
      for(int i=0;i<n;i++){
          if(units+arr[i]>mx){
              units=arr[i];
              painter++;
          }else{
              units+=arr[i];
          }
      }
      return painter<=k;
  }
    long long minTime(int arr[], int n, int k)
    {
        long long ans=0;
        long long sum=0;
        long long mx=-1;
        for(int i=0;i<n;i++){
            sum+=arr[i];
           if(mx<arr[i])
           mx=arr[i];
        }
        long long s=mx,e=sum;
        while(s<=e){
            long long mid=s+(e-s)/2;
            if(ifpossible(arr,n,k,mid)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
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