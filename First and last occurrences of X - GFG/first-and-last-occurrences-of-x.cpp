// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  int first(vector<int>&arr,int n ,int x){
      int ind=-1;
      int start=0,end=n-1;
      while(start<=end){
          int mid=start+(end-start)/2;
          
          if(arr[mid]==x){
              
              ind=mid;
              end=mid-1;
              
          }else if(arr[mid]>x){
              
              end=mid-1;
          }else{
              
              start=mid+1;
              
          }
      }
      return ind;
  }
  int last(vector<int>&arr,int n ,int x){
      int ind=-1;
      int start=0,end=n-1;
      while(start<=end){
          int mid=start+(end-start)/2;
          
          if(arr[mid]==x){
              
              ind=mid;
              start=mid+1;
              
          }else if(arr[mid]>x){
              
              end=mid-1;
          }else{
              
              start=mid+1;
              
          }
      }
      return ind;
  }
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        // Code here
        int frst=first(arr,n,x);
        int lst=last(arr,n,x);
        if(frst!=-1)
        return {frst,lst};
        else 
        return {-1};
       
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> ans= obj.firstAndLast(arr, n, x) ;
        for(int i:ans){
            cout<<i<<" ";
        }
        cout<< endl;
    }
    return 0;
}
  // } Driver Code Ends