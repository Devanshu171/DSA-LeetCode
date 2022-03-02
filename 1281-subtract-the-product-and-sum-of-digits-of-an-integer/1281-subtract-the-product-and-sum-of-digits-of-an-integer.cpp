class Solution {
public:
    int subtractProductAndSum(int n) {
        int k=n;
        int sum=0;
        int p=1;
        while(k!=0){
            int r=k%10;
            k/=10;
            sum+=r;
                p*=r;
        }
        return p-sum;
    }
};