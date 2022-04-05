// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string s){
        // code here 
        int op=0,cl=0,swaps=0,unbalanced=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='['){
                op++;
                if(unbalanced>0){
                    swaps+=unbalanced;
                    unbalanced--;
                }
            }else{
                cl++;
                unbalanced=cl-op;
            }
        }
        return swaps;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends