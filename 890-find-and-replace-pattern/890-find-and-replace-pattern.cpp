class Solution {
public:
    
    bool match(string &pattern,string &word){
        if(pattern.size()!=word.size()) return false;
       unordered_map<char,int>mpp1,mpp2;
        int count=1;
        string pat1="",pat2="";
        for(int i=0;i<pattern.size();i++){
            if(mpp1.find(pattern[i])!=mpp1.end()){
                pat1+=mpp1[pattern[i]]+'0';
            }else{
                mpp1[pattern[i]]=count;
                pat1+=count+'0';
                count++;
            }
        }
        count=1;
         for(int i=0;i<word.size();i++){
            if(mpp2.find(word[i])!=mpp2.end()){
                pat2+=mpp2[word[i]]+'0';
            }else{
                mpp2[word[i]]=count;
                pat2+=count+'0';
                count++;
            }
        }
        
        return pat1==pat2;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        int n=words.size();
        for(int i=0;i<n;i++){
            if(match(pattern,words[i])){
                ans.push_back(words[i]);
            }
        }
        
        return ans;
        
        
    }
};