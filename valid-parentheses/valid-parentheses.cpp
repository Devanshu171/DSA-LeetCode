class Solution {
public:
    bool isValid(string x) {
        stack<char>st;
        
        for(int i=0;i<x.size();i++){
            
            if(x[i]=='{'||x[i]=='['||x[i]=='(') st.push(x[i]);
            else if(st.empty()) return false;
            else if(x[i]==']'){
                if(st.top()!='[') 
                return false;
                st.pop();
            }
             else if(x[i]=='}'){
                if(st.top()!='{') 
                return false;
                 st.pop();
            }
             else if(x[i]==')'){
                if(st.top()!='(') 
                return false;
                 st.pop();
            }
        }
        return st.empty();
        
    }
};