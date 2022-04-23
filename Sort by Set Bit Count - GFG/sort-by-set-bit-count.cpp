// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int countsetbit(int n){
        int count=0;
        while(n){
            count+=n&1;
            n>>=1;
        }
        return count;
    }
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        
        vector<pair<int,pair<int,int>>>vec;
        for(int i=0;i<n;i++){
            vec.push_back({countsetbit(arr[i]),{arr[i],i}});
        }
        sort(vec.begin(),vec.end(),[&](pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b){
            return a.first==b.first?(a.second.second)<(b.second.second):a.first>b.first;
        });
        for(int i=0;i<n;i++){
            arr[i]=vec[i].second.first;
        }
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends