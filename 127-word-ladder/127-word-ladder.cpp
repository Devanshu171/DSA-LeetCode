class Solution {
public:
    int diff(string s2,string s1){
        int cnt=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i])
                cnt++;
        }
        return cnt;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
                queue<string>q;
        q.push(beginWord);
        unordered_set<string>st,words;
        st.insert(beginWord);
        for(auto it:wordList){
            words.insert(it);
        }
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
                    if(words.count(t) && !st.count(t)){
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