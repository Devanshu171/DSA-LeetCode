// { Driver Code Starts
// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends
     #include<unordered_map>
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string s1, string s2)
    {
         if(s1.size()!=s2.size())
         return false;
        int map[256]={-1};
         bool isMark[256]={0};
        for(int i=0;i<256;i++){
            map[i]=-1;
            isMark[i]=false;
        }
         for(int i=0;i<s1.size();i++){
             if(map[s1[i]]!=-1){
                 if(char(map[s1[i]])!=s2[i])
                 return false;
             }else{
                
                 if(isMark[s2[i]])
                 return false;
                 else{
                   map[s1[i]]=s2[i];
                   isMark[s2[i]]=1;
                 }
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