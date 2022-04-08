class Solution {
public:
    int countRemoval(string s){
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
    void solve(string s,int cnt,unordered_set<string>&st,vector<string>&ans){
        if(st.count(s))
            return;
        st.insert(s);
        if(cnt==0){
            if(countRemoval(s)==0)
            ans.push_back(s);
            return;
        }
        for(int i=0;i<s.size();i++){
            string left=s.substr(0,i);
            string right=s.substr(i+1);
            solve(left+right,cnt-1,st,ans);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string>st;
        vector<string>ans;
        int cnt=countRemoval(s);
        solve(s,cnt,st,ans);
        return ans;
        
    }
};