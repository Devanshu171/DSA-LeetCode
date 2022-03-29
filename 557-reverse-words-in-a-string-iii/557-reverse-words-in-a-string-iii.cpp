class Solution {
public:
    void reverse(string &s,int i,int j){
        for(;i<j;i++,j--){
            char temp=s[i];
            s[i]=s[j];
            s[j]=temp;
        }
    }
    string reverseWords(string s) {
        
        int i=0,j=0;
        while(j<s.size()){
            if(s[j]==' '){
                reverse(s,i,j-1);
                j++;
                i=j;
            }else{
                j++;
            }
        }
        reverse(s,i,j-1);
        return s;
    }
};