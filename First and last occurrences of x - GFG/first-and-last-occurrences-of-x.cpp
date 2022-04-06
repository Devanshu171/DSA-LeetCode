// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

int bs(int arr[],int n,int x,int flag){
    int s=0,e=n-1,ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==x){
            ans=mid;
            if(flag){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }else if(arr[mid]>x){
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return ans;
}

vector<int> find(int arr[], int n , int x )


{
    int first=bs(arr,n,x,0);
    if(!first==-1) return {-1};
    
int last= bs(arr,n,x,1);
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