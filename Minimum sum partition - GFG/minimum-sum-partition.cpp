// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
    int solveTabu(int arr[],int n){
        int sum=0;
        for(int i=0;i<n;i++)sum+=arr[i]; 
        vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
        for(int i=0;i<n;i++) dp[i][0]=true;
        if(sum<=arr[0]) dp[0][arr[0]]=true;
        
        for(int i=1;i<n;i++){
            for(int target=1;target<=sum;target++){
                bool notTake=dp[i-1][target];
                bool take=false;
                
                if(arr[i]<=target) take=dp[i-1][target-arr[i]];
                
                dp[i][target]= (take||notTake);
            }
        }
        
        int ans=INT_MAX;
        for(int target=1;target<=sum;target++){
            if(dp[n-1][target]==true){
                ans=min(ans,abs(target-(sum-target)));
            }
        }
        
        return ans;
    }
	int minDifference(int arr[], int n)  { 
            return solveTabu(arr,n);
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
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends