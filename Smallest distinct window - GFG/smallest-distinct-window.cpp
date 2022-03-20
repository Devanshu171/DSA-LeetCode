// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    string findSubString(string s)
    {
       
        unordered_set<int>st;
        unordered_map<char,int>mpp;
         int n=s.size();
        for(int i=0;i<n;i++)
        st.insert(s[i]);
        
        int dis_count=st.size();
        int ans=n;  int start;
        int i=0,j=0;
        
        while(j<n){
            mpp[s[j]]++;
           
                while(mpp.size()==dis_count){
                    if(ans>j-i+1){
                        ans=j-i+1;
                        start=i;
                    }
                    mpp[s[i]]--;
                    if(mpp[s[i]]==0)
                    mpp.erase(s[i]);
                    i++;
                    
                }
            j++;
        }
        return s.substr(start,ans);
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str).size() << endl;
    }
    return 0;
}  // } Driver Code Ends