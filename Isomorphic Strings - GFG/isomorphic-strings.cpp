// { Driver Code Starts
// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
            int mpp[256];
            bool isMap[256];
            for(int i=0;i<256;i++){
                mpp[i]=-1;
               isMap[i]=false;
            }
            if(str1.size()!=str2.size())
            return false;
            for(int i=0;i<str1.size();i++){
                // cout<<str1[i]<<endl;
                if(mpp[str1[i]]==-1){
                    // cout<<"first"<<endl;
                    if(isMap[str2[i]])
                    return false;
                    else{
                        mpp[str1[i]]=str2[i];
                      isMap[str2[i]]=true;
                    }
                }else{
                    // cout<<char(mpp[str1[i]+'a']+'a')<<" ";
                    // cout<<"second"<<endl;
                    if(str2[i]!=char(mpp[str1[i]]))
                    return false;
                }
            }
            return true;
                }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends