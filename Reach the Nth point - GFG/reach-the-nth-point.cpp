// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		int nthPoint(int n){
		    // Code here
		    int m=1000000000+7;
		    if(n<=1) return n;
		   int  prev1=1,prev2=1;
		   for(int i=2;i<=n;i++){
		       int cur=(prev1+prev2)%m;
		       prev2=prev1;
		       prev1=cur;
		   }
		   return prev1;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends