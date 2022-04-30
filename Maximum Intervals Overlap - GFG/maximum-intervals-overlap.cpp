// { Driver Code Starts
// Program to find maximum guest at any time in a party
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	public:
	vector<int> findMaxGuests(int entry[], int exitt[], int n)
	{
	   // Your code goes here
	   sort(entry,entry+n);
	   sort(exitt,exitt+n);
	  int last_entered;
	   int j=0;
	   int cnt=0;
	   vector<int>ans(2,0);
	   for(int i=0;i<n;i++){
	       if(entry[i]<=exitt[j]){
	           cnt++;
	           //cout<<cnt<<endl;
	           last_entered=entry[i];
	       }else{
	           if(ans[0]<cnt){
	               ans[0]=cnt;
	               ans[1]=last_entered;
	           }
	           cnt--;
	           j++;
	           i--;
	       }
	   }
	   if(ans[0]<cnt){
	        ans[0]=cnt;
	               ans[1]=last_entered;
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
        int n,i;
        cin>>n;
        int entry[n],exit1[n];
        for(i=0;i<n;i++)
        cin>>entry[i];
        for(i=0;i<n;i++)
        cin>>exit1[i];
        Solution obj;

	    vector<int> p = obj.findMaxGuests(entry, exit1, n);
	    cout<<p[0]<<' '<<p[1];
	    cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends