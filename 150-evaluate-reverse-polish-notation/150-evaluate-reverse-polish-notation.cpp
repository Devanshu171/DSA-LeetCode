class Solution {
public:
    int evaluate(int a,int b,string x){
        if(x=="*")
            return a*b;
        else if(x=="/")
            return a/b;
        else if(x=="+")
            return a+b;
        else
            return a-b;
        
         
        return -1;
    }
    int evalRPN(vector<string>& s) {
        stack<int>st;
        
        for(int i=0;i<s.size();i++){
            string x=s[i];
            if(x!="*" && x!="/" && x!="+" && x!="-"){
                st.push(stoi(x));
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