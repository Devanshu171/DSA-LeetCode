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
    int op=0,cl=0;
    if(s.size()&1) return -1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='{'){
            op++;
        }else{
            if(op==0){
                cl++;
            }else{
                op--;
            }
        }
    }
    if((op+cl)&1) return -1;
    return (op+1)/2+(cl+1)/2;
}