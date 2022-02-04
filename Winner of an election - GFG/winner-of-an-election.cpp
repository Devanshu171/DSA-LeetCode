// { Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        unordered_map<string,int>mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        
            int max=0;
            string s="";
        for(int i=0;i<n;i++){
            if(mpp[arr[i]]>max){
            max=mpp[arr[i]];
            s=arr[i];
            }
            if(mpp[arr[i]]==max)
            {
                if(s>arr[i])
                s=arr[i];
            }
            
        }
        // string a='max';
        return {s,to_string(max)};
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}
  // } Driver Code Ends