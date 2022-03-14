class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int mxlen=1;
        int start=0;
        int h,l;
        for(int i=0;i<n;i++){
            
            l=i-1;
            h=i;
            while(l>=0 && h<n && s[l]==s[h]){
                if(h-l+1>mxlen){
                    mxlen=h-l+1;
                    start=l;
                }
                l--;
                h++;
            }
            
             l=i-1;
            h=i+1;
            while(l>=0 && h<n && s[l]==s[h]){
                if(h-l+1>mxlen){
                    mxlen=h-l+1;
                    start=l;
                }
                l--;
                h++;
            }
        }
        return s.substr(start,mxlen);
    }
};