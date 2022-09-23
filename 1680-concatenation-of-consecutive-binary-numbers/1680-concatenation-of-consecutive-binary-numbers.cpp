class Solution {
public:
    #define mod 1000000007
    int concatenatedBinary(int n) {
        
        string ans="";
        for(int i=n;i>=1;i--){
            int k=i;
            while(k){
                ans+=(k%2)+'0';
                k/=2;
            }           
        }
        
       long long int  res=0;
       long long int mult=1;
        for(int i=0;i<ans.size();i++){
             long long now=(mult*(ans[i]-'0'))%mod;
            mult*=2;
            mult%=mod;
             res+=now;
        
           
        }
        return res%mod;
        return 1;
    }
};