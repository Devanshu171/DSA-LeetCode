class Solution {
public:
    bool checkIfPangram(string s) {
        int count[26]={0};
        for(auto it:s){
            count[it-'a']++;
        }
        for(int i=0;i<26;i++){
            if(!count[i]) return false;
        }
        return true;
    }
};