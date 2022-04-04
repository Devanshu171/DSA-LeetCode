// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char>st;
        for(int i=0;i<x.size();i++){
            char k=x[i];
            if(k=='['||k=='('|| k=='{'){
                st.push(k);
            }
            else{
                if(st.empty())
                return false;
                char s=st.top();
                st.pop();
                if(k==']'){
                    if(s!='[')
                    return false;
                }else if(k=='}'){
                     if(s!='{')
                    return false;
                }else{
                     if(s!='(')
                    return false;
                }
                
            }
        }
        return st.empty();
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends