class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<string>q;
        unordered_set<string>st,words;
        for(auto it:wordList){
            words.insert(it);
        }
        q.push(beginWord);
        st.insert(beginWord);
        int count=0;
        while(!q.empty()){
            count++;
            int n=q.size();
            for(int i=0;i<n;i++){
                string s=q.front();
                q.pop();
                if(s==endWord)
                    return count;
                string t;
                for(int i=0;i<s.size();i++){
                    t=s;
                    for(char j='a';j<='z';j++){
                        t[i]=j;
                        if(!st.count(t) && words.count(t)){
                            st.insert(t);
                            q.push(t);
                        }
                    }
                }
            }
        }
        
        return 0;
    }
};