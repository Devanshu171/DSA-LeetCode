class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s, s1;;
        
        int n=word1.size(), m=word2.size();
         
        for(int i=0;i<n;i++)
                s+=word1[i];
        
        
         for(int i=0;i<m;i++)
                s1+=word2[i];
        
        return s==s1;
    }
};