// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	
	public:
	#define ll long long 
	long long countTriplets(long long arr[], int n, long long sum)
	{
            ll ans=0;
            sort(arr,arr+n);
            for(int i=0;i<n;i++){
                ll diff=sum-arr[i];
                int s=i+1,e=n-1;
                while(s<e){
                    ll sum2=arr[s]+arr[e];
                    if(sum2<diff){
                        ans+=e-s;
                        s++;
                    }else{
                        e--;
                    }
                    
                    
                }
            }
            return ans;
	}
		 

};

// { Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends