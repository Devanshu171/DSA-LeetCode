// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


bool findPair(int arr[], int n, int diff){
    //code
    sort(arr,arr+n);
    
  
    for(int i=0;i<n;i++){
        int s=i+1,e=n-1,t=arr[i]+diff;
        // cout<<t<<endl;
        while(s<=e){
            int mid=s+(e-s)/2;
            // cout<<arr[mid]<<endl;
            if(arr[mid]==t) return true;
            else if(arr[mid]>t) e=mid-1;
            else s=mid+1;
        }
    }
        return false;
}