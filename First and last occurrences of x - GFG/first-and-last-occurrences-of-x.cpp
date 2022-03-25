// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

int bs(int arr[],int n,int x,int dir){
    int start=0,end=n-1,ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==x){
            ans=mid;
            if(dir==0){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }else if(arr[mid]<x){
           start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return ans;
}

vector<int> find(int arr[], int n , int x )
{
    // code here
    int first=bs(arr,n,x,0);
    if(first==-1)return {-1,-1};
    int last=bs(arr,n,x,1);
    return {first,last};
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends