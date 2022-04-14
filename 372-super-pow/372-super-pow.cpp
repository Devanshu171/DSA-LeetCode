class Solution {
public:
    int pow(int a,int b,int m){
        int res=1;
        while(b>0){
            if(b&1){
                res=(res*(1LL)*a)%m;
            }
            a=(a*(1LL)*a)%m;
            b>>=1;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        /*
                --> a^12345
                a^1=a^0(1) * a^1
                a^12 = a^10 * a^2
                a^123 = a^120 * a^3
                a^1234 = a^1230 * a^4 
                a^12345 = a^12340 * a^5
                
                a^10 = (a^1)^10....  a^1 * a^1 * a^1....10 times  
                
                so, res=1;
                res=res^10*a^b[i];
        
        */
        
        int res=1;
        for(auto digit:b){
            res=(pow(res,10,1337)*pow(a,digit,1337))%1337;
        }
        return res;
    }
};