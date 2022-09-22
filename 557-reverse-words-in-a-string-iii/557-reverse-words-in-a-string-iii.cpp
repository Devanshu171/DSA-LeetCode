class Solution {
public:
    void reverse(string &s,int i,int j){
        while(i<j){
            swap(s[i++],s[j--]);
        }
    }
        
    string reverseWords(string s) {
        int prev=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                reverse(s,prev,i-1);
                prev=i+1;
            }
        }
        reverse(s,prev,s.size()-1);
        return s;
    }
};