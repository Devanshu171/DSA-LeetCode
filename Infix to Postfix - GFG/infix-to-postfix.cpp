// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int precedence(char x){
        if(x=='^')
        return 5;
       else if(x=='*' || x=='/')
        return 3;
        else if(x=='-' || x=='+')
        return 2;
        else
        return 1;
    }
    bool isAlpha(char x){
        return (x>='a' && x<='z') || (x>='A' && x<='Z');
    }
    bool isLeftToRightAssociative(char x){
        if(x=='^')
            return false;
            else
            return true;
    }
    string infixToPostfix(string s) {
        // Your code here
        
        stack<char>st;
        string ans="";
        for(int i=0;i<s.size();i++){
            char x=s[i];
            if(isAlpha(x)){
                ans.push_back(x);
            }else{
                if(x=='('){
                    st.push(x);
                }else if(x==')'){
                    while( !st.empty() && st.top()!='('){
                        ans.push_back(st.top());
                        st.pop();
                    }
                    st.pop();
                }else{
                    
                    while( !st.empty() && precedence(st.top())>=precedence(x)){
                        ans.push_back(st.top());
                        st.pop();
                    }
                    st.push(x);
                    
                }
            }
            
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};


// { Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}
  // } Driver Code Ends