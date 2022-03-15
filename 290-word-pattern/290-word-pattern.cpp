class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>words;
        string v;
        stringstream iss(s);
        while(iss>>v) words.push_back(v);
        if(pattern.size()!=words.size()) return false;
        unordered_map<char,string>mpp;
        unordered_set<string>st;
        for(int i=0;i<pattern.size();i++){
            char ch=pattern[i];
            if(mpp.find(ch)!=mpp.end()){
                if(mpp[ch]!=words[i])
                    return false;
            }else{
                if(st.count(words[i])) return false;
                mpp[ch]=words[i];
                st.insert(words[i]);
            }
        }
        return true;
    
    }
};