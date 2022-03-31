class Solution {
public:
    string removeOccurrences(string s, string part) {
        string st="";
        for(int i=0;i<s.size();i++){
            st.push_back(s[i]);
            if(st.size()>=part.size()){
                if(st.substr(st.size()-part.size(),part.size())==part){
                    int x=part.size();
                    while(x--)
                        st.pop_back();
                }
            }
        }
        return st;
    }
};