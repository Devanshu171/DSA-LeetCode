// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    string findSubString(string s)
    {
        // Your code goes here 
        unordered_map<char,int>mpp1,mpp2;
        for(int i=0;i<s.size();i++){
            mpp1[s[i]]++;
        }
        int count=mpp1.size();
        int i=0,j=0,ans=s.size(),start=0;
        while(j<s.size()){
            mpp2[s[j]]++;
          
             if(mpp2.size()==count){
                while(mpp2.size()==count){
                    if(j-i+1<ans){
                        ans=j-i+1;
                        start=i;
                    }
                    mpp2[s[i]]--;
                    if(mpp2[s[i]]==0)
                    mpp2.erase(s[i]);
                    i++;
                }
                
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