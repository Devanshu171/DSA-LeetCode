// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(long long a[], int n) ;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<ll, ll> pp = getMinMax(a, n);

        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}// } Driver Code Ends

#define ll long long
pair<long long, long long> getMinMax(long long arr[], int n) {
   ll min,max;
   int i;
   if(n&1){
       min=max=arr[0];
       i=1;
   }else{
       if(arr[0]<arr[1]){
           max=arr[1];
           min=arr[0];
       }else{
           min=arr[1];
           max=arr[0];
       }
       i=2;
   }
   for(;i<n-1;i+=2){
       ll a=arr[i];
       ll b=arr[i+1];
    //   cout<<a<<" "<<b<<endl;
       if(a>b){
           if(max<a){
               max=a;
           }
           if(min>b){
               min=b;
           }
       }else{
           if(b>max){
               max=b;
           }
           if(min>a){
               min=a;
           }
       }
   }
    return make_pair(min,max);
}