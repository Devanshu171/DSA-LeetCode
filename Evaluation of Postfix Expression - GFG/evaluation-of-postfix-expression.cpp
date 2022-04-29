// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluate(int a,int b,char x){
        switch(x){
            
            case '*': return a*b;
                    
            case '+': return a+b;
            
            case '/': return a/b;
                    
            case '-': return a-b;

            
        }
    }
    int evaluatePostfix(string s)
    {
        stack<int>st;
        for(int i=0;i<s.size();i++){
            char x=s[i];
            if(x>='0' && x<='9'){
                st.push((x-'0'));
            }else{
                int op2=st.top();
                st.pop();
                int op1=st.top();
                st.pop();
                int res=evaluate(op1,op2,x);
                st.push(res);
            }
        }
        return st.top();
        
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends