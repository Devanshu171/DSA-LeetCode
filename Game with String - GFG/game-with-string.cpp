// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        int count[26]={0};
        priority_queue<int>pq;
        for(int i=0;i<s.size();i++){
            count[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if((count[i]>0)){
                pq.push(count[i]);
            }
        }
        while(k--){
            int a=pq.top();
            pq.pop();
            pq.push(a-1);
        }
        int ans=0;
        while(!pq.empty()){
            ans+=pq.top()*pq.top();
            pq.pop();
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends