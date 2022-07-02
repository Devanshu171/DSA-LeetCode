class Solution {
public:
    #define mod 1000000007
    int distinctSubseqII(string s) {
         long long int count[s.size()];
        count[0]=2;
        unordered_map<char,long>mpp;
        
        mpp[s[0]]=1;
        
        for(int i=1;i<s.size();i++){
            int rep=0;
            if(mpp.find(s[i])!=mpp.end()){
                rep=mpp[s[i]];
            }
            
            count[i]=((count[i-1]%mod)*2)%mod;
            count[i]-=rep%mod;
        if(count[i]<0) count[i]+=mod;
                mpp[s[i]]=count[i-1]%mod;
                
            
        }
        
        return count[s.size()-1]%mod-1;
    }
};