// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    #define ll long long
    ll merge(ll arr[],ll low,ll mid,ll high){
        ll i=low,j=mid;
        ll temp[high-low+1];
        ll k=0;
        ll ans=0;
        while(i<mid && j<=high){
            if(arr[i]<=arr[j]){
                temp[k++]=arr[i++];
            }else{
                ans+=mid-i;
                temp[k++]=arr[j++];
            }
        }
        while(i<mid) temp[k++]=arr[i++];
        while(j<=high) temp[k++]=arr[j++];
        k=0;
        for(i=low;i<=high;i++)
        arr[i]=temp[k++];
        
        return ans;
    }
    ll mergesort(ll arr[],ll low,ll high){
        ll ans=0;
        if(low<high){
            ll mid=low+(high-low)/2;
            ans+=mergesort(arr,low,mid);
            ans+=mergesort(arr,mid+1,high);
            ans+=merge(arr,low,mid+1,high);
        }
        return ans;
    }
    long long int inversionCount(long long arr[], long long n)
    {
        return mergesort(arr,0,n-1);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends