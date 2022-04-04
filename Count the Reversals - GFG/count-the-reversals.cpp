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
    stack<char>st;
    for(int i=0;i<s.size();i++){
        if(!st.empty() && s[i]=='}'){
            if(st.top()=='{')
            st.pop();
            else{
                st.push(s[i]);
            }
        }else{
            st.push(s[i]);
        }
    }
        int op=0,cl=0;
        while(!st.empty()){
            if(st.top()=='{') op++;
            else cl++;
            st.pop();
        }
        return (cl+1)/2+(op+1)/2;
    
}