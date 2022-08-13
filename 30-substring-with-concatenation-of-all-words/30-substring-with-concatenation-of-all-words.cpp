class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>mpp;
        for(auto it:words) mpp[it]++;
        vector<int>ans;
        int wordCount=words.size();
        int wordLen=words[0].size();
        if(wordCount*wordLen>s.size()) return {};
        
        for(int i=0;i<=s.size()-(wordCount*wordLen);i++){
            unordered_map<string,int>seen;
            
            for(int j=0;j<wordCount;j++){
                 int nextIndex=i+j*wordLen;
                string word=s.substr(nextIndex,wordLen);
                // cout<<word<<endl;
                if(mpp.find(word)==mpp.end()){
                    break;
                }
                seen[word]++;
                if(seen[word]>mpp[word]) break;
                if(j+1==wordCount) ans.push_back(i);
            }
            
           
        }
        return ans;
    }
};