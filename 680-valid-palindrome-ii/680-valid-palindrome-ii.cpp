class Solution {
public:
    bool checkpal(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1,ans=0;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                return (checkpal(s,i+1,j))||(checkpal(s,i,j-1));
            }
        }
        return true;
    }
};