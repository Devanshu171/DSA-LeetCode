class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string alpha[26]={".-","-...","-.-.","-..",".","..-.","--.",
                          "....","..",".---","-.-",".-..","--","-.",
                          "---",".--.","--.-",".-.","...","-","..-",
                          "...-",".--","-..-","-.--","--.."};
        unordered_map<char,string>mpp;
        for(int i=0;i<26;i++){
            mpp[i+'a']=alpha[i];
        }
        
        unordered_set<string>ans;
        for(int i=0;i<words.size();i++){
            string str=words[i];
            string cur="";
            for(int j=0;j<str.size();j++){
                    cur+=mpp[str[j]];
            }
          ans.insert(cur);
        }
        return ans.size();
    }
};