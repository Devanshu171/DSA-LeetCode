// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    typedef long long LL;
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    if(n<m) return -1;
    LL ans=INT_MAX;
    LL i=0,j=m-1;
    sort(a.begin(),a.end());
    while(j<n){
        if(ans>a[j]-a[i]){
            ans=a[j]-a[i];
        }
        i++;
        j++;
    }
    return ans;
    
    }   
};

// { Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}  // } Driver Code Ends