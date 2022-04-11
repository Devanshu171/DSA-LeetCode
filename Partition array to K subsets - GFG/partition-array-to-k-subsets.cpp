// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
 
  bool solve(int ind,int sum,int k,int tsum,int a[],int n,vector<int>&vis ){
     if(k==0)
     return true;
     if(sum==tsum)
     {
        return solve(0,0,k-1,tsum,a,n,vis);
     }
     if( sum>tsum)
     return false;
     
     for(int i=ind;i<n;i++){
         if(!vis[i]){
             vis[i]=1;
             if(solve(i+1,sum+a[i],k,tsum,a,n,vis))
             return true;
           else  vis[i]=0;
         }
         
     }
       return false;
     
  }
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         int tsum=0;
         for(int i=0;i<n;i++){
             tsum+=a[i];
         }
         if(k>n) return false;
         int sum=tsum/k;
         if(sum*k!=tsum) return false;
      
         vector<int>vis(n,0);
         
           return   solve(0,0,k,sum,a,n,vis);

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
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends