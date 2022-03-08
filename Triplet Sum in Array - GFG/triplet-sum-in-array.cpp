// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find2Numbers(int a[],int s,int n,int x){
    unordered_set<int>st;
    for(int i=s;i<n;i++){
        int dif=x-a[i];
        if(st.count(dif)) return true;
        st.insert(a[i]);
    }
    return false;
}
bool find3Numbers(int a[], int n, int x)
{
    for(int i=0;i<n;i++){
        int diff=x-a[i];
        if(find2Numbers(a,i+1,n,diff)) return true;
    }
    return false;
    
}

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends