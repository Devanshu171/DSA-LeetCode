class Solution {
public:
    bool isPalin(string s){
        int n=s.size();
        if(n==0) return false;
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1]) return false;
        }
        
        return true;
    }
    
    int countPalin(int ind,string &s){
        if(ind==s.size()) return 0;
        
        int cnt=0;
        
        for(int i=ind;i<s.size();i++){
            cnt+=isPalin(s.substr(ind,i-ind+1));
        }

        return cnt+ countPalin(ind+1,s);
    }
    int countSubstrings(string s) {
        return countPalin(0,s);
        // cout<<s.substr(2,2)<<endl;
        // return 6;
        
     }
};