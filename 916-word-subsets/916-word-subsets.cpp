class Solution {
public:
    
    vector<int> freqCount(string &s1){
        vector<int>count(26,0);
        for(int i=0;i<s1.size();i++){
            count[s1[i]-'a']++;
        }
        return count;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        vector<int>maxCount(26,0);
        for(int i=0;i<words2.size();i++){
            vector<int> count=freqCount(words2[i]);
            for(int i=0;i<26;i++){
                maxCount[i]=max(maxCount[i],count[i]);
            }
        }
        
        for(auto it:words1){
            vector<int>count=freqCount(it);
            int i;
            for( i=0;i<26;i++){
                if(count[i]<maxCount[i]) break;
            }
            if(i==26) ans.push_back(it);
        }
        return ans;
        
    }
};