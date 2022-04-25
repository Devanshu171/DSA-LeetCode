// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
  
    bool solve(int ind, int sum,int k,int tsum,int a[],int n,vector<int>&temp){
        
        if(k==1)
        return true;
        if(sum==tsum){
            return solve(0,0,k-1,tsum,a,n,temp);
        }
        
        
        for(int i=ind;i<n;i++){
            if(sum+a[i]<=tsum && temp[i]==0){
                temp[i]=1;
                if(solve(i+1,sum+a[i],k,tsum,a,n,temp))
                return true;
                temp[i]=0;
            }
        }
        return false;
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
        
         int sum=0;
         for(int i=0;i<n;i++){
             sum+=a[i];
         }
         if(sum%k!=0 || k>n)
         return false;
         vector<int>temp(n,0);
         return solve(0,0,k,sum/k,a,n,temp);
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