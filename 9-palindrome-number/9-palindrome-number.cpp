class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int y=x;
        long long r=0;
        while(y){
            r=r*10+y%10;
            y/=10;
            
        }
        return r==x;
    }
};