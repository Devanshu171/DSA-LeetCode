// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

#define ll long long
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    ll merge(ll arr[],ll low,ll mid,ll high){
        ll i=low,j=mid,k=0;
        ll temp[high-low+1];
        ll ans=0;
        while(i<mid && j<=high){
            if(arr[i]>arr[j]){
                ans+=mid-i;
                temp[k++]=arr[j++];
            }else{
                temp[k++]=arr[i++];
            }
        }
        while(i<mid) temp[k++]=arr[i++];
        while(j<=high) temp[k++]=arr[j++];
        k=0;
        for(int i=low;i<=high;i++){
            arr[i]=temp[k++];
        }
        return ans;     
    }
    ll mergesort(ll arr[],ll low,ll high){
        ll total=0;
        if(low<high){
            ll mid=low+(high-low)/2;
            total+=mergesort(arr,low,mid);
            total+=mergesort(arr,mid+1,high);
            total+=merge(arr,low,mid+1,high);
        }
        return total;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        return mergesort(arr,0,N-1);
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