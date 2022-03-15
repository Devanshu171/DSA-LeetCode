class Solution {
public:
    long long int bs(int n){
        int s=0,e=n;
                    long long int ans=-1;
        while(s<=e){
               long long int mid=s+(e-s)/2;
                long long int sq=mid*mid;

            if(sq==n) return mid;
            else if(sq<n){
                ans=mid;
                s=mid+1;
            }
            else e=mid-1;
        }
        return ans;
    }
    int mySqrt(int x) {
        return bs(x);
    }
};