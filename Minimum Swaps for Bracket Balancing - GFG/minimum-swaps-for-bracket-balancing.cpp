// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string s){
        // code here 
        int n=s.size();
        vector<int>pos;
        for(int i=0;i<n;i++){
            if(s[i]=='[')
            pos.push_back(i);
        }
        int op=0,p=0,swaps=0;
        for(int i=0;i<n;i++){
            if(s[i]=='['){
                op++;
                p++;
            }else{
                if(op>0){
                    op--;
                }else{
                    // cout<<"thid si s"<<endl;
                    int k=pos[p];
                    p++;
                    // cout<<k<<" "<<i<<endl;
                    swaps+=k-i;
                    // cout<<swaps<<endl;
                    while(k>i){
                        swap(s[k],s[k-1]);
                        k--;
                    }
                    op++;
                }
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