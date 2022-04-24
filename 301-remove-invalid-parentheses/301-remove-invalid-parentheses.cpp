class Solution {
public:
    int minRemoval(string s){
        int op=0,cl=0;
        for(int i=0;i<s.size();i++){
            // cout<<op<<" "<<cl<<endl;
            if(s[i]=='('){
                op++;
            }else if(s[i]==')'){
                if(op>0)
                    op--;
                else{
                    cl++;
                }
            }
        }
        // cout<<op<<" "<<cl<<endl;
        return (op+cl);
    }
    void solve(string s,int count,vector<string>&ans,unordered_set<string>&st){
      if(st.count(s))
          return;
        st.insert(s);
        if(count==0){
            if(minRemoval(s)==0){
                ans.push_back(s);
               
            }
            return;
        }
        for(int i=0;i<s.size();i++){
            string left=s.substr(0,i);
            string right=s.substr(i+1);
            solve(left+right,count-1,ans,st);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        
        int count=minRemoval(s);
        vector<string>ans;
        unordered_set<string>st;
        solve(s,count,ans,st);
        return ans;
    }
};