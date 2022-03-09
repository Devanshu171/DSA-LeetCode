class Solution {
public:
    bool checkRecord(string s) {
        int n=s.size();
        int a=0,l=0;
        for(int i=0;i<n;i++){
            if(s[i]=='A') a++;
            else if(s[i]=='L'){
                int k=i;
                while(k<n && s[k]=='L') k++;
                if(k-i>=3) return false;
            }
        }
        return a<2?true:false;
    }
};