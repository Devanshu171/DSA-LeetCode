class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>st;
        deque<char>q;
        int i=0,j=0;
        
        while(j<s.size()){
            q.push_back(s[j]);
            if(j-i+1==k){
                
                st.insert({q.begin(),q.end()});
                q.pop_front();
                i++;
            }
            j++;
        }
        
        return st.size()==pow(2,k);
    }
};