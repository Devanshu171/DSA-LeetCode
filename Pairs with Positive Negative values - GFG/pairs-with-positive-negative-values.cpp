// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    vector<int> PosNegPair(int a[], int n) {
        unordered_map<int,int>st;
        for(int i=0;i<n;i++){
            st[a[i]]++;
        }
        sort(a,a+n);
        vector<int>vec;
        int k=0;
         while(a[k]<=0) k++;
        //  cout<<k<<endl;
        for(int i=k;i<n;i++){
           
            if(st.find(-a[i])!=st.end()){
                vec.push_back(-a[i]);
                vec.push_back(a[i]);
                st[-a[i]]--;
                if(st[-a[i]]==0)
                st.erase(-a[i]);
            }
        }
        return vec;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> v = obj.PosNegPair(a, n);

        if (v.size() == 0) cout << "0";

        for (auto it : v) cout << it << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends