// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    #define ll long long
    public:
    long long trappingWater(int arr[], int n){
        // code here
        int right[n],left[n];
        int lx=-1,rx=-1;
        for(int i=0;i<n;i++){
            lx=max(lx,arr[i]);
            rx=max(rx,arr[n-i-1]);
            left[i]=lx;
            right[n-i-1]=rx;
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            ans+=min(left[i],right[i])-arr[i];
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends