class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long k=0;
        long long i=0;
        while(k<n){
            k=pow(2,i);
              if(k==n) return true;
            i++;
        }
        return false;
    }
};