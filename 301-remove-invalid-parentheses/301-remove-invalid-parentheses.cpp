class Solution {
public:
    int minRemoval(string s){
        int op=0,cl=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                op++;
            }else if(s[i]==')'){
                if(op>0){
                    op--;
                }else{
                    cl++;
                }
            }  
        }
        return op+cl;
    }
    
    void solve(int k,string s,vector<string>&ans,unordered_set<string>&st){
        
        if(st.count(s)){
            return;
        }
        st.insert(s);
        if(k==0){
            if(minRemoval(s)==0){
                ans.push_back(s);
            }
            return;
        }
     
        
        for(int i=0 ;i<s.size();i++){ 
            string left=s.substr(0,i);
            string right=s.substr(i+1);
            solve(k-1,left+right,ans,st);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string>ans;
        unordered_set<string>st;
        
        
        int k=minRemoval(s);
        solve(k,s,ans,st);
        return ans;
        
    }
};