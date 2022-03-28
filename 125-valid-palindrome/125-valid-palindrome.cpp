class Solution {
public:
    void tolower(string &s){
        for(int i=0;i<s.size();i++){
            if(s[i]>='A'&& s[i]<='Z'){
                s[i]=s[i]-'A'+'a';
            }
        }
    }
    bool ischar(char x){
        return ((x>='a'&&x<='z')||(x>='0' && x<='9'));
    }
    bool isPalindrome(string s) {
        tolower(s);
        cout<<s<<endl;
        int i=0,j=s.size()-1;
        while(i<j){
            if(!ischar(s[i])){
                i++;
            }else if(!ischar(s[j])){
                j--;
            }else if(s[i]==s[j]){
                i++;
                j--;
            }else{
                return false;
            }
        }
           return true;
    }
 
};