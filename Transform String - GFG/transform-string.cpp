// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
   
    int transform (string a, string b)
    {
        //code here.
        if(a.size()!=b.size()) return -1;
        int count[256]={0};
        for(int i=0;i<a.size();i++){
            count[a[i]]++;
            count[b[i]]--;
        }
        for(int i=0;i<256;i++){
            if(count[i]!=0) 
            return -1;
        }
        
                int j=b.size()-1;
        int ans=0,i=a.size()-1;
        while(i>=0){
            if(a[i]==b[j]){
                i--;
                j--;
            }else{
                while(i>=0&&a[i]!=b[j]){
                    i--;
                ans++;
                }
                
            }
        }
        return ans;
        
    }
};


// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}  // } Driver Code Ends