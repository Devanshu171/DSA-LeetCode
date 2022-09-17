class Solution {
public:
    void toLower(string &s){
        for(int i=0;i<s.size();i++){
            if(s[i]>='A' && s[i]<='Z'){
                s[i]=s[i]-'A'+'a';
            }
        }
    }
    bool isPalindrome(string s) {

            int i=0,j=s.size()-1;
        toLower(s);
        while(i<j){
            while( i<j && !isalpha(s[i]) && !(s[i]>='0' && s[i]<='9')) i++;
           while(i<j && !isalpha(s[j]) &&  !(s[j]>='0' && s[j]<='9'))j--;
                if(s[i]!=s[j]) return false;
                i++;
                j--;
        }
        return true;
    }
};