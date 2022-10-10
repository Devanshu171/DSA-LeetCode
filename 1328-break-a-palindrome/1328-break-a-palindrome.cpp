class Solution {
public:
    bool checkPalin(string s){
        
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
    string breakPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            
            for(char j='a';j<'z';j++){
                string temp=s;
                temp[i]=j;
                if(!checkPalin(temp)){
                    if(ans.size()==0 || ans>temp)
                    ans=temp;
                    break;
                }
            }
        }
        return ans;
    }
};