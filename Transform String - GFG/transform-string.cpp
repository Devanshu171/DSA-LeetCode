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
        int n=a.size();
        int m=b.size();
        int i=n-1;
        int j=m-1;
        if(n!=m)
        return -1;
        int res=0;
        int arr[256]={0};
        for(int i=0;i<n;i++){
            arr[a[i]]++;
            arr[b[i]]--;
        }
        for(int i=0;i<256;i++){
            if(arr[i]!=0)
            return -1;
        }
        while(i>=0){
            if(a[i]==b[j]){
                i--;
                j--;
            }else{
                while(i>=0 && a[i]!=b[j]){
                    i--;
                    res++;
                }
            }
        }
        return res;
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