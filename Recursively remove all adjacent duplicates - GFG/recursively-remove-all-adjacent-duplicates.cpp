// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    string rremove(string s){
        // code here
        string ans="";
        int n=s.size();
        
        int i=0;
        while(i<n){
            char ch=s[i];
            int cnt=0;
            while(s[i]==ch){
                cnt++;i++;
            }
            if(cnt==1)ans+=ch;
        }
        
        if(ans==s)
        return ans;
        
        return rremove(ans);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}  // } Driver Code Ends