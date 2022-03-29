// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    
    
    static bool cmp(pair<int,pair<int,int>> &aa,pair<int,pair<int,int>>  &bb){
          
        
        if(aa.first==bb.first)
        return aa.second.first<bb.second.first;
        else 
        return aa.first>bb.first;
        
    }
    int countSetbit(int n){
      int  count=0;
        while(n){
            count+=n&1;
            n>>=1;
        }
        return count;
    }
    void sortBySetBitCount(int arr[], int n)
    {
        vector<pair<int,pair<int,int>>>vec;
        for(int i=0;i<n;i++){
            int k=countSetbit(arr[i]);
            vec.push_back({k,{i,arr[i]}});
        }
        sort(vec.begin(),vec.end(),cmp);
        for(int i=0;i<n;i++){
            arr[i]=vec[i].second.second;
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