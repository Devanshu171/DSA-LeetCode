// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int n){
        // code here
        vector<int>ans;
        ans.push_back(1);
        for(int i=1;i<=n;i++){
            int c=0;
            for(int j=0;j<ans.size();j++){
                int val=ans[j]*i+c;
                ans[j]=val%10;
                c=val/10;
            }
            while(c!=0){
                ans.push_back(c%10);
                c/=10;
            } 
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends