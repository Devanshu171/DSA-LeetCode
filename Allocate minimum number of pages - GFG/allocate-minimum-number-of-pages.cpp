// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool ispossible(int arr[],int n,int m,int mx){
        int students=1,sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum>mx){
                students++;
                sum=arr[i];
            }
        }
        return students<=m;
    }
    int findPages(int arr[], int n, int m) 
    {
        //code here
        int low=-1,high=0,ans=-1;
        for(int i=0;i<n;i++){
            high+=arr[i];
            low=max(low,arr[i]);
        }
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ispossible(arr,n,m,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends