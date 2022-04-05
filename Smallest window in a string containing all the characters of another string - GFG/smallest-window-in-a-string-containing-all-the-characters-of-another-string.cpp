// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        unordered_set<char>st;
        unordered_map<char,int>mpp;
        for(int i=0;i<p.size();i++){
        mpp[p[i]]++;
        st.insert(p[i]);
        }
        
        int count=mpp.size();
        int j=0,i=0,start=-1,len=s.size();
        while(j<s.size()){
            if(st.count(s[j])){
                // cout<<i<<" "<<j<<endl;
                mpp[s[j]]--;
                if(mpp[s[j]]==0)
                count--;
                // cout<<count<<endl;
            }
            if(count>0) j++;
            else if(count==0){
                while(i<=j && count==0){
                if(len>j-i+1){
                    len=j-i+1;
                    start=i;
                }
                if(st.count(s[i])){
                    mpp[s[i]]++;
                    if(mpp[s[i]]==1)
                    count++;
                }
                i++;
            }
            j++;
            }
        }
        return start==-1?"-1":(s.substr(start,len));
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends