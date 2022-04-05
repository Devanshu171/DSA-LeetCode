// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        unordered_map<char,int>mpp;
                 mpp['I']=1;
                mpp['V']= 5;
                mpp['X']=10;
                mpp['L']=50;
                mpp['C'] =100;
                mpp['D']=500;
                mpp['M']=1000;
                
                int ans=0,prev=0;
                
                for(int i=str.size()-1;i>=0;i--){
                    if(mpp[str[i]]>=prev){
                        ans+=mpp[str[i]];
                        prev=mpp[str[i]];
                    }else{
                        ans-=mpp[str[i]];
                        prev=mpp[str[i]];
                    }
                }
                return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}  // } Driver Code Ends