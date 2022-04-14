class Solution {
public:
    double myPow(double x, int n) {
        double res=1.0;
        int m=abs(n);
        while(m>0){
            if(m&1){
                res=res*x;
            }
            x=x*x;
            m>>=1;
        }
        if(n<0)
            return (double)1/res;
            
        
        return res;
    }
};