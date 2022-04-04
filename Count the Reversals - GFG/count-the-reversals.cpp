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
    if(s.size()&1) return -1;
    int op=0,cl=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='{')
        op++;
        else{
            if(op<=0)
            cl++;
            else{
                op--;
            }
        }
    }
    return (op+1)/2+(cl+1)/2;
}