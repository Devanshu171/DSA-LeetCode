// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        int count[26]={0};
        for(int i=0;i<str.size();i++)
        count[str[i]-'a']++;
        
        int mx=1;
        char ans=str[0];
        for(int i=1;i<str.size();i++){
            // cout<<count[str[i]-'a']<<endl;
            if(count[str[i]-'a']>mx){
                    mx=count[str[i]-'a'];
                    ans=str[i];
            }else if(count[str[i]-'a']==mx && str[i]<ans){
                ans=str[i];
            }
        }
        return ans;
    }

};

// { Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}  // } Driver Code Ends