class Solution {
public:
    int consecutiveNumbersSum(int n) {
        
        int ans=0;
        
        for(int i=1;i*(i+1)<n*2;i++){
            double a=(1.0*n-(i*(i+1))/2)/(i+1);
            if(a-int(a)==0.0) ans++;
        }
        return ans+1;
    }
};