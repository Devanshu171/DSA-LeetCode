// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    // your code here
    stack<char>st;
    int n=s.size();
    if(n&1) return -1;
    int op=0,cl=0;
        for(int i=0;i<n;i++){
           if(s[i]=='{') op++;
           else{
               if(op==0) cl++;
               else op--;
           }
        }
    return (cl+1)/2+(op+1)/2;
}